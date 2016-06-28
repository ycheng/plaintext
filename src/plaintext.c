#include <gdk/gdk.h>
#include <gtk/gtk.h>

void text_request_callback(GtkClipboard *clipboard,
                           const gchar *text,
                           gpointer data)
{
    gtk_clipboard_set_text(clipboard, text, -1);
    gtk_main_quit();
}

int main(int argc, char** argv)
{
    gtk_init(&argc, &argv);

    GtkClipboard* clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);

    // This is just an arbitrary value.
    int value = 0xDECAFBAD;

    gtk_clipboard_request_text(clipboard, text_request_callback, &value);
    gtk_main();

    return 0;
}
