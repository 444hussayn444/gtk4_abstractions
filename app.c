#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include <gdk/gdk.h>
#include <stdlib.h>
#include "gtk_f.h"


GtkWidget *create_widget(char *widget_type, char *widget_name, char *text)
{
  GtkWidget *widget;
  if (strcmp(widget_type, "label") == 0){
    if (text == NULL){
      printf("Error, Text Must Be Inserted");
    }
    if (widget_name != NULL){
      widget = gtk_label_new(text);
      GtkStyleContext *ctx = gtk_widget_get_style_context(widget);
      gtk_style_context_add_class(ctx, widget_name);
      return widget;
    }
    widget = gtk_label_new(text);
    return widget;
  }

  if (strcmp(widget_type, "input") == 0) {
    if (text == NULL){
      printf("Error, Text Must Be Inserted\n");
    }
    if (widget_name){
      widget = gtk_editable_label_new(text);
      GtkStyleContext *ctx = gtk_widget_get_style_context(widget);
      gtk_style_context_add_class(ctx, widget_name);
      return widget;
    }
    widget = gtk_button_new_with_label(text);
    return widget;
  }

  if (strcmp(widget_type, "button") == 0){
    if (text == NULL){
      printf("Error, Text Must Be Inserted\n");
    }
    if (widget_name){
      widget = gtk_button_new_with_label(text);
      GtkStyleContext *ctx = gtk_widget_get_style_context(widget);
      gtk_style_context_add_class(ctx, widget_name);
      return widget;
    }
    widget = gtk_button_new_with_label(text);
    return widget;
  }
  if (widget == NULL){
    printf("No Widget.");
    exit(0);
  }

  return widget;
}

void css_file_handler(const char *file){
  
  if (file == NULL || *file == '\0')
    {
      printf("Can not recogonize css file, or it's not found.\n");
      exit(0);
    }
  GtkCssProvider *css_provider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(css_provider), file);
  gtk_style_context_add_provider_for_display(
					     gdk_display_get_default(),
					     GTK_STYLE_PROVIDER(css_provider),
					     GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
					     );
  g_object_unref(css_provider);
}

// full page component system - tomorrow - or at night i do no know;




/*void grid_system(GtkWidget* grid_box,GtkWidget* widget,int row , int col , int x,int y )
{
  gtk_grid_attach(GTK_GRID(grid_box), widget, row ,col, x, y);
 
}
/*
  void activate_window(GtkApplication *application, gpointer user_data)
  {
  char widget_label[5] = "label";
  char widget_button[6] = "button";
  char widget_input[5] = "input";

  char* file = "style.css";
  
  css_file_handler(file);

  
  GtkWidget *grid_box = gtk_grid_new();
  GtkWidget *window = gtk_application_window_new(application);
  GtkWidget *label = create_widget(widget_label, widget_label, "hello world");
  
  grid_system(GTK_WIDGET(grid_box),label,0,0,11,11);

  
  gtk_window_set_child(GTK_WINDOW(window), grid_box);
  gtk_window_set_title(GTK_WINDOW(window), "APPLICATION-FOR-FREE");
  gtk_window_set_default_size(GTK_WINDOW(window), 1000, 700);
  gtk_window_present(GTK_WINDOW(window));
  }
*/
int initialize_application(int args, char *argvs[])
{
  gtk_init();
  GtkApplication *application = gtk_application_new("Rabber.org", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(application, "activate", G_CALLBACK(activate_window), NULL);
  int status = g_application_run(G_APPLICATION(application), args, argvs);
  g_object_unref(application);
  return status;
}

int main(int args, char *argvs[])
{
  int status = initialize_application(args, argvs);
  return status;
}
