#ifndef GUI_H
#define GUI_H

#pragma once
#include <gtk/gtk.h>

#include "caen_dt547x_board.h"
#include "caen_usb_protocol.h"

// Main Windows
extern GtkWidget *window;
extern GtkBuilder *builder;
extern GtkWidget *fixed;

// Board Connection dashboard
extern GtkWidget *label_status;
extern GtkWidget *label_command;
extern GtkWidget *btn_connect;
extern GtkWidget *btn_disconnect;
extern GtkWidget *btn_ch1_enable;
extern GtkWidget *btn_alarm_reset;
extern GtkWidget *btn_refresh;

// Command dashboard
extern GtkWidget *combo_cmd;
extern GtkWidget *entry_cmd_val;
extern GtkWidget *btn_send;

// Flags labels
extern GtkWidget *flag_buttons[16];

// Monitor Labels
extern GtkWidget *label_voltage_level;
extern GtkWidget *label_current_level;
extern GtkWidget *label_vset;
extern GtkWidget *label_iset;
extern GtkWidget *label_ramp_up;
extern GtkWidget *label_ramp_down;
extern GtkWidget *label_trip;

// Mode switches
extern GtkWidget *btn_imrange;
extern GtkWidget *btn_power_down_mode;

// Helper Functions
void refresh_gui_monitor(caen_hv_state* s);
void init_gui();
void clear_flags();

// GTK Signals
void on_btn_connect_clicked(GtkButton *b);
void on_btn_disconnect_clicked(GtkButton *b);
void on_btn_send_clicked(GtkButton* b);
void on_btn_alarm_reset_clicked(GtkButton *b);
void on_btn_ch1_enable_state_set(GtkSwitch* b);
void on_btn_monitor_clicked(GtkButton * b);
void on_btn_imrange_state_set(GtkSwitch * s);
void on_btn_power_down_mode_state_set(GtkSwitch * s);


// Define functions dispatcher
typedef void (*command)(caen_hv_state*, float);

enum gtk_set_cmd{SET_VSET,SET_ISET,SET_RAMP_UP,SET_RAMP_DOWN,SET_TRIP};

extern command commands[5];

#endif
