#include <gdk/gdk.h>
#include <gtk/gtk.h>

static void text_request_callback(GtkClipboard *clipboard,
                           const gchar *text, gpointer data) {
  if (text != NULL) gtk_clipboard_set_text(clipboard, text, -1);
}

static
gboolean window_event_notification(
    GtkWidget *widget,
    GdkEventWindowState *event,
    gpointer user_data)
{
  if (event->new_window_state & GDK_WINDOW_STATE_ICONIFIED) return TRUE;
  if (event->new_window_state & GDK_WINDOW_STATE_FOCUSED) {
    GtkClipboard* clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    gtk_clipboard_request_text(clipboard, text_request_callback, NULL);
  }

  return TRUE;
}

static GtkWidget *window = NULL;
static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  if (window == NULL) {
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Plain Text");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 100);

    g_signal_connect(G_OBJECT(window), "window-state-event", G_CALLBACK(window_event_notification), NULL);

    GtkWidget *button;
    button = gtk_button_new_with_label ("Quit");
    g_signal_connect_swapped (button, "clicked",
			      G_CALLBACK (gtk_widget_destroy),
                              window);

    gtk_container_add (GTK_CONTAINER (window), button);

    gtk_widget_show_all (window);
  } else {
    gtk_window_present(GTK_WINDOW(window));
  }
}

int main(int argc, char** argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("net.ycheng.plaintext", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
