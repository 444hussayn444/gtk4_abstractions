#ifndef GTK_T
#define GTK_T

#include <gtk/gtk.h>

GtkWidget* create_widget(char* widget_type, char* widget_name, char* text);

void css_file_handelr(const char *file);

int initialize_application(int args,char* argvs[]);

#endif

