#include <gtk/gtk.h>
#include <stdio.h>

#define NINE 9

struct calc {
        GtkWidget *window;
        GtkWidget *child;
        GtkWidget *display;
        GtkWidget *buttons;
        GtkWidget *button[NINE];
};

void activate(GtkApplication *app, gpointer user_data) {
        struct calc widget;
        GtkWidget *window;

        widget.window = gtk_application_window_new(app);
        gtk_window_set_default_size(GTK_WINDOW(widget.window), 300, 300);
        gtk_window_set_resizable(GTK_WINDOW(widget.window), false);

        widget.child = gtk_grid_new();
        gtk_grid_set_column_homogeneous(GTK_GRID(widget.child), true);
        gtk_grid_set_row_homogeneous(GTK_GRID(widget.child), true);
        gtk_window_set_child(GTK_WINDOW(widget.window), widget.child);

        widget.display = gtk_frame_new("My GTK Application");

        widget.buttons = gtk_grid_new();
        gtk_grid_set_column_homogeneous(GTK_GRID(widget.buttons), true);
        gtk_grid_set_row_homogeneous(GTK_GRID(widget.buttons), true);

        int x = 0;
        int y = 0;
        for (int i = 1; i <= NINE; ++i) {
                char label[1];
                sprintf(label, "%d", i);
                widget.button[i] = gtk_button_new_with_label(label);

                gtk_grid_attach(GTK_GRID(widget.buttons), widget.button[i], y, x, 1, 1);

                if ((++y) == 3) {
                        y = 0;
                        ++x;
                }
        }

        gtk_grid_attach(GTK_GRID(widget.child), widget.display, 0, 0, 1, 1);
        gtk_grid_attach(GTK_GRID(widget.child), widget.buttons, 0, 1, 1, 3);

        gtk_window_present(GTK_WINDOW(widget.window));
}

int main(int argc, char **argv) {
        GtkApplication *app;
        int status;

        gtk_init();
        app = gtk_application_new("org.gtk.calculator", G_APPLICATION_DEFAULT_FLAGS);

        g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
        status = g_application_run(G_APPLICATION(app), argc, argv);
        g_object_unref(app);

        return status;
}
