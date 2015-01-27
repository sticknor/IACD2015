// TO DO:
// make it so the minute is always right, even if that means if then start

#include <pebble.h>
  
static Window *s_main_window;

// Anaimation Values
AppTimer *timer;
int frame;

int hour;
int minute = 1;
int lastHour;
int lastMinute = -1;

// Background
static BitmapLayer *s_background_layer;
static GBitmap *s_background_bitmap;
static GBitmap *s_edge;

// Eye Bitmaps
static GBitmap *s_frame_0_a;
static GBitmap *s_frame_0_b;
static GBitmap *s_frame_1_a;
static GBitmap *s_frame_1_b;
static GBitmap *s_frame_2_a;
static GBitmap *s_frame_2_b;
static GBitmap *s_frame_3_a;
static GBitmap *s_frame_3_b;
static GBitmap *s_frame_4_a;
static GBitmap *s_frame_4_b;
static GBitmap *s_frame_5_a;
static GBitmap *s_frame_5_b;
static GBitmap *s_frame_6_a;
static GBitmap *s_frame_6_b;

// Eye Layers
static BitmapLayer *s_eye_1_a;
static BitmapLayer *s_eye_1_b;
static BitmapLayer *s_eye_2_a;
static BitmapLayer *s_eye_2_b;
static BitmapLayer *s_eye_3_a;
static BitmapLayer *s_eye_3_b;
static BitmapLayer *s_eye_4_a;
static BitmapLayer *s_eye_4_b;
static BitmapLayer *s_eye_5_a;
static BitmapLayer *s_eye_5_b;
static BitmapLayer *s_eye_6_a;
static BitmapLayer *s_eye_6_b;
static BitmapLayer *s_eye_7_a;
static BitmapLayer *s_eye_7_b;
static BitmapLayer *s_eye_8_a;
static BitmapLayer *s_eye_8_b;
static BitmapLayer *s_eye_9_a;
static BitmapLayer *s_eye_9_b;
static BitmapLayer *s_eye_10_a;
static BitmapLayer *s_eye_10_b;
static BitmapLayer *s_eye_11_a;
static BitmapLayer *s_eye_11_b;
static BitmapLayer *s_eye_12_a;
static BitmapLayer *s_eye_12_b;

static BitmapLayer *s_edge_mask;
static GBitmap *s_minute_1;
static BitmapLayer *s_minute; 

// Time and Animate
static void moveMinute(){
    struct GBitmap* minuteImage = s_minute_1;
    struct GPoint origin = minuteImage->bounds.origin;
    if (minute > 0 && minute < 16){
      if (minute%2 == 0){
       s_minute_1->bounds.origin.x = -1*((minute/2)+1);
       s_minute_1->bounds.origin.y = -1*(minute/2);
      }
      else{
       s_minute_1->bounds.origin.x = -1*(minute/2);
       s_minute_1->bounds.origin.y = -1*((minute/2)+1);
      }
    }
    else if (minute > 15 && minute < 31){
      if (minute%2 == 0){
       s_minute_1->bounds.origin.x = -8+(minute/4);
       s_minute_1->bounds.origin.y = -8-((minute-1)/4);
      }
      else{
       s_minute_1->bounds.origin.x = -7+((minute-1)/4);
       s_minute_1->bounds.origin.y = -7-((minute)/4);
      }
    }
    else if (minute > 30 && minute < 46){
      if (minute%2 == 0){
       s_minute_1->bounds.origin.x = ((minute-30)/2)+1;
       s_minute_1->bounds.origin.y = -16+((minute-30)/2);
      }
      else{
       s_minute_1->bounds.origin.x = ((minute-30)/2);
       s_minute_1->bounds.origin.y = -16+((minute-29)/2);
      }
    }
    else {
      if (minute%2 == 0){
       s_minute_1->bounds.origin.x = 7-(((minute-45)/2)+1);
       s_minute_1->bounds.origin.y = -8+((minute-45)/2);
      }
      else{
       s_minute_1->bounds.origin.x = 7-((minute-45)/2);  
       s_minute_1->bounds.origin.y = -8+(((minute-45)/2)+1);
      }
    }
}

static void update_time() {
  
   BitmapLayer *hourEye_a;
   BitmapLayer *hourEye_b;
  if (hour == 0) {
   bitmap_layer_set_bitmap(s_eye_11_a, s_frame_6_a);
   bitmap_layer_set_bitmap(s_eye_11_b, s_frame_6_b);
   hourEye_a = s_eye_12_a;
   hourEye_b = s_eye_12_b;
  }
  else if (hour == 1){
   bitmap_layer_set_bitmap(s_eye_12_a, s_frame_6_a);
   bitmap_layer_set_bitmap(s_eye_12_b, s_frame_6_b);
   hourEye_a = s_eye_1_a;
   hourEye_b = s_eye_1_b;    
  }
  else if (hour == 2){
   bitmap_layer_set_bitmap(s_eye_1_a, s_frame_6_a);
   bitmap_layer_set_bitmap(s_eye_1_b, s_frame_6_b);
   hourEye_a = s_eye_2_a;
   hourEye_b = s_eye_2_b;    
  }
  else if (hour == 3){
   bitmap_layer_set_bitmap(s_eye_2_a, s_frame_6_a);
   bitmap_layer_set_bitmap(s_eye_2_b, s_frame_6_b);
   hourEye_a = s_eye_3_a;
   hourEye_b = s_eye_3_b;    
  }
  else if (hour == 4){
   bitmap_layer_set_bitmap(s_eye_3_a, s_frame_6_a);
   bitmap_layer_set_bitmap(s_eye_3_b, s_frame_6_b);
   hourEye_a = s_eye_4_a;
   hourEye_b = s_eye_4_b;    
  }
  else if (hour == 5){
   bitmap_layer_set_bitmap(s_eye_4_a, s_frame_6_a);
   bitmap_layer_set_bitmap(s_eye_4_b, s_frame_6_b);
   hourEye_a = s_eye_5_a;
   hourEye_b = s_eye_5_b;    
  }
  else if (hour == 6){
   bitmap_layer_set_bitmap(s_eye_5_a, s_frame_6_a);
   bitmap_layer_set_bitmap(s_eye_5_b, s_frame_6_b);
   hourEye_a = s_eye_6_a;
   hourEye_b = s_eye_6_b;    
  }
  else if (hour == 7){
   bitmap_layer_set_bitmap(s_eye_6_a, s_frame_6_a);
   bitmap_layer_set_bitmap(s_eye_6_b, s_frame_6_b);
   hourEye_a = s_eye_7_a;
   hourEye_b = s_eye_7_b;    
  }
  else if (hour == 8){
   bitmap_layer_set_bitmap(s_eye_7_a, s_frame_6_a);
   bitmap_layer_set_bitmap(s_eye_7_b, s_frame_6_b);
   hourEye_a = s_eye_8_a;
   hourEye_b = s_eye_8_b;    
  }
  else if (hour == 9){
   bitmap_layer_set_bitmap(s_eye_8_a, s_frame_6_a);
   bitmap_layer_set_bitmap(s_eye_8_b, s_frame_6_b);
   hourEye_a = s_eye_9_a;
   hourEye_b = s_eye_9_b;    
  }
  else if (hour == 10){
   bitmap_layer_set_bitmap(s_eye_9_a, s_frame_6_a);
   bitmap_layer_set_bitmap(s_eye_9_b, s_frame_6_b);
   hourEye_a = s_eye_10_a;
   hourEye_b = s_eye_10_b;    
  }
  else if (hour == 11){
   bitmap_layer_set_bitmap(s_eye_10_a, s_frame_6_a);
   bitmap_layer_set_bitmap(s_eye_10_b, s_frame_6_b);
   hourEye_a = s_eye_11_a;
   hourEye_b = s_eye_11_b;    
  }
  else{
   bitmap_layer_set_bitmap(s_eye_10_a, s_frame_6_a);
   bitmap_layer_set_bitmap(s_eye_10_b, s_frame_6_b);
   hourEye_a = s_eye_11_a;
   hourEye_b = s_eye_11_b;
  }

 if (frame == 0){
   frame = 1;
   bitmap_layer_set_bitmap(hourEye_a, s_frame_1_a);
   bitmap_layer_set_bitmap(hourEye_b, s_frame_1_b);
   timer = app_timer_register(100, (AppTimerCallback) update_time, NULL);
 } else if(frame ==1){
   frame = 2;
   bitmap_layer_set_bitmap(hourEye_a, s_frame_1_a);
   bitmap_layer_set_bitmap(hourEye_b, s_frame_1_b);
   timer = app_timer_register(100, (AppTimerCallback) update_time, NULL);
  } else if(frame ==2){
    frame = 3;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_2_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_2_b);
    timer = app_timer_register(100, (AppTimerCallback) update_time, NULL);
  } else if(frame ==3){
    frame = 4;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_3_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_3_b);
    timer = app_timer_register(100, (AppTimerCallback) update_time, NULL);
  } else if(frame ==4){
    frame = 5;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_4_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_4_b);   
    timer = app_timer_register(100, (AppTimerCallback) update_time, NULL);  
  } else if(frame ==5){
    frame = 6;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_5_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_5_b);
    timer = app_timer_register(100, (AppTimerCallback) update_time, NULL);
  } else if(frame ==6){
    frame = 7;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_6_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_6_b);
  } else if(frame ==7){
    frame = 8;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_5_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_5_b);
    timer = app_timer_register(100, (AppTimerCallback) update_time, NULL);
  } else if(frame ==8){
    frame = 9;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_4_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_4_b);
    timer = app_timer_register(100, (AppTimerCallback) update_time, NULL);
  } else if(frame ==9){
    frame = 10;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_3_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_3_b);
    timer = app_timer_register(100, (AppTimerCallback) update_time, NULL);
  } else if(frame ==10){
    frame = 11;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_2_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_2_b);
    timer = app_timer_register(100, (AppTimerCallback) update_time, NULL);
  } else if(frame ==11){
    frame = 12;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_1_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_1_b);
    timer = app_timer_register(100, (AppTimerCallback) update_time, NULL);
  } else{
    frame = 0;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_1_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_1_b);
  }
}

static void main_window_load(Window *window) {
  // Load GBitmaps with Resources
  s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_background);

  s_frame_0_a = gbitmap_create_with_resource(RESOURCE_ID_Frame_0_a);
  s_frame_0_b = gbitmap_create_with_resource(RESOURCE_ID_Frame_0_b);
  s_frame_1_a = gbitmap_create_with_resource(RESOURCE_ID_Frame_1_a);
  s_frame_1_b = gbitmap_create_with_resource(RESOURCE_ID_Frame_1_b);
  s_frame_2_a = gbitmap_create_with_resource(RESOURCE_ID_Frame_2_a);
  s_frame_2_b = gbitmap_create_with_resource(RESOURCE_ID_Frame_2_b);
  s_frame_3_a = gbitmap_create_with_resource(RESOURCE_ID_Frame_3_a);
  s_frame_3_b = gbitmap_create_with_resource(RESOURCE_ID_Frame_3_b);
  s_frame_4_a = gbitmap_create_with_resource(RESOURCE_ID_Frame_4_a);
  s_frame_4_b = gbitmap_create_with_resource(RESOURCE_ID_Frame_4_b);
  s_frame_5_a = gbitmap_create_with_resource(RESOURCE_ID_Frame_5_a);
  s_frame_5_b = gbitmap_create_with_resource(RESOURCE_ID_Frame_5_b);
  s_frame_6_a = gbitmap_create_with_resource(RESOURCE_ID_Frame_6_a);
  s_frame_6_b = gbitmap_create_with_resource(RESOURCE_ID_Frame_6_b);
  
  s_edge = gbitmap_create_with_resource(RESOURCE_ID_edge_mask);

  s_minute_1 = gbitmap_create_with_resource(RESOURCE_ID_Minute_1);

  // Initialize and Size Layers
  s_background_layer = bitmap_layer_create(GRect(0, 0, 144, 168));

  s_minute = bitmap_layer_create(GRect(0, 0, 144, 168));
  s_edge_mask = bitmap_layer_create(GRect(0, 0, 144, 168));

  s_eye_1_a = bitmap_layer_create(GRect(0, 0, 48, 42));
  s_eye_1_b = bitmap_layer_create(GRect(0, 0, 48, 42));
  s_eye_2_a = bitmap_layer_create(GRect(48, 0, 48, 42));
  s_eye_2_b = bitmap_layer_create(GRect(48, 0, 48, 42));
  s_eye_3_a = bitmap_layer_create(GRect(96, 0, 48, 42));
  s_eye_3_b = bitmap_layer_create(GRect(96, 0, 48, 42));
  s_eye_4_a = bitmap_layer_create(GRect(0, 42, 48, 42));
  s_eye_4_b = bitmap_layer_create(GRect(0, 42, 48, 42));
  s_eye_5_a = bitmap_layer_create(GRect(48, 42, 48, 42));
  s_eye_5_b = bitmap_layer_create(GRect(48, 42, 48, 42));
  s_eye_6_a = bitmap_layer_create(GRect(96, 42, 48, 42));
  s_eye_6_b = bitmap_layer_create(GRect(96, 42, 48, 42));
  s_eye_7_a = bitmap_layer_create(GRect(0, 84, 48, 42));
  s_eye_7_b = bitmap_layer_create(GRect(0, 84, 48, 42));
  s_eye_8_a = bitmap_layer_create(GRect(48, 84, 48, 42));
  s_eye_8_b = bitmap_layer_create(GRect(48, 84, 48, 42));
  s_eye_9_a = bitmap_layer_create(GRect(96, 84, 48, 42));
  s_eye_9_b = bitmap_layer_create(GRect(96, 84, 48, 42));
  s_eye_10_a = bitmap_layer_create(GRect(0, 126, 48, 42));
  s_eye_10_b = bitmap_layer_create(GRect(0, 126, 48, 42));
  s_eye_11_a = bitmap_layer_create(GRect(48, 126, 48, 42));
  s_eye_11_b = bitmap_layer_create(GRect(48, 126, 48, 42));
  s_eye_12_a = bitmap_layer_create(GRect(96, 126, 48, 42));
  s_eye_12_b = bitmap_layer_create(GRect(96, 126, 48, 42));

  //Match Bitmaps to Layers and Add Layer to Window
  bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_background_layer)); 


  
  bitmap_layer_set_bitmap(s_minute, s_minute_1);
  bitmap_layer_set_compositing_mode (s_minute, GCompOpAnd);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_minute));
  
  bitmap_layer_set_bitmap(s_edge_mask, s_edge);
  bitmap_layer_set_compositing_mode (s_edge_mask, GCompOpSet);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_edge_mask));
  
  
  bitmap_layer_set_bitmap(s_eye_1_a, s_frame_6_a);
  bitmap_layer_set_compositing_mode (s_eye_1_a, GCompOpSet);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_1_a));
  bitmap_layer_set_bitmap(s_eye_1_b, s_frame_6_b);
  bitmap_layer_set_compositing_mode (s_eye_1_b, GCompOpAnd);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_1_b));

  bitmap_layer_set_bitmap(s_eye_2_a, s_frame_6_a);
  bitmap_layer_set_compositing_mode (s_eye_2_a, GCompOpSet);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_2_a));
  bitmap_layer_set_bitmap(s_eye_2_b, s_frame_6_b);
  bitmap_layer_set_compositing_mode (s_eye_2_b, GCompOpAnd);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_2_b));

  bitmap_layer_set_bitmap(s_eye_3_a, s_frame_6_a);
  bitmap_layer_set_compositing_mode (s_eye_3_a, GCompOpSet);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_3_a));
  bitmap_layer_set_bitmap(s_eye_3_b, s_frame_6_b);
  bitmap_layer_set_compositing_mode (s_eye_3_b, GCompOpAnd);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_3_b));

  bitmap_layer_set_bitmap(s_eye_4_a, s_frame_6_a);
  bitmap_layer_set_compositing_mode (s_eye_4_a, GCompOpSet);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_4_a));
  bitmap_layer_set_bitmap(s_eye_4_b, s_frame_6_b);
  bitmap_layer_set_compositing_mode (s_eye_4_b, GCompOpAnd);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_4_b));

  bitmap_layer_set_bitmap(s_eye_5_a, s_frame_6_a);
  bitmap_layer_set_compositing_mode (s_eye_5_a, GCompOpSet);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_5_a));
  bitmap_layer_set_bitmap(s_eye_5_b, s_frame_6_b);
  bitmap_layer_set_compositing_mode (s_eye_5_b, GCompOpAnd);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_5_b));

  bitmap_layer_set_bitmap(s_eye_6_a, s_frame_6_a);
  bitmap_layer_set_compositing_mode (s_eye_6_a, GCompOpSet);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_6_a));
  bitmap_layer_set_bitmap(s_eye_6_b, s_frame_6_b);
  bitmap_layer_set_compositing_mode (s_eye_6_b, GCompOpAnd);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_6_b));

  bitmap_layer_set_bitmap(s_eye_7_a, s_frame_6_a);
  bitmap_layer_set_compositing_mode (s_eye_7_a, GCompOpSet);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_7_a));
  bitmap_layer_set_bitmap(s_eye_7_b, s_frame_6_b);
  bitmap_layer_set_compositing_mode (s_eye_7_b, GCompOpAnd);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_7_b));

  bitmap_layer_set_bitmap(s_eye_8_a, s_frame_6_a);
  bitmap_layer_set_compositing_mode (s_eye_8_a, GCompOpSet);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_8_a));
  bitmap_layer_set_bitmap(s_eye_8_b, s_frame_6_b);
  bitmap_layer_set_compositing_mode (s_eye_8_b, GCompOpAnd);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_8_b));

  bitmap_layer_set_bitmap(s_eye_9_a, s_frame_6_a);
  bitmap_layer_set_compositing_mode (s_eye_9_a, GCompOpSet);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_9_a));
  bitmap_layer_set_bitmap(s_eye_9_b, s_frame_6_b);
  bitmap_layer_set_compositing_mode (s_eye_9_b, GCompOpAnd);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_9_b));

  bitmap_layer_set_bitmap(s_eye_10_a, s_frame_6_a);
  bitmap_layer_set_compositing_mode (s_eye_10_a, GCompOpSet);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_10_a));
  bitmap_layer_set_bitmap(s_eye_10_b, s_frame_6_b);
  bitmap_layer_set_compositing_mode (s_eye_10_b, GCompOpAnd);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_10_b));

  bitmap_layer_set_bitmap(s_eye_11_a, s_frame_6_a);
  bitmap_layer_set_compositing_mode (s_eye_11_a, GCompOpSet);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_11_a));
  bitmap_layer_set_bitmap(s_eye_11_b, s_frame_6_b);
  bitmap_layer_set_compositing_mode (s_eye_11_b, GCompOpAnd);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_11_b));

  bitmap_layer_set_bitmap(s_eye_12_a, s_frame_6_a);
  bitmap_layer_set_compositing_mode (s_eye_12_a, GCompOpSet);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_12_a));
  bitmap_layer_set_bitmap(s_eye_12_b, s_frame_6_b);
  bitmap_layer_set_compositing_mode (s_eye_12_b, GCompOpAnd);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_eye_12_b));
}

static void main_window_unload(Window *window) {
  app_timer_cancel(timer);

  gbitmap_destroy(s_background_bitmap);
  gbitmap_destroy(s_frame_0_a);
  gbitmap_destroy(s_frame_0_b);
  gbitmap_destroy(s_frame_1_a);
  gbitmap_destroy(s_frame_1_b);
  gbitmap_destroy(s_frame_2_a);
  gbitmap_destroy(s_frame_2_b);
  gbitmap_destroy(s_frame_3_a);
  gbitmap_destroy(s_frame_3_b);
  gbitmap_destroy(s_frame_4_a);
  gbitmap_destroy(s_frame_4_b);
  gbitmap_destroy(s_frame_5_a);
  gbitmap_destroy(s_frame_5_b);
  gbitmap_destroy(s_frame_6_a);
  gbitmap_destroy(s_frame_6_b);
  
  gbitmap_destroy(s_edge);
  
  gbitmap_destroy(s_minute_1);
  
  bitmap_layer_destroy(s_background_layer);
  bitmap_layer_destroy(s_eye_1_a);
  bitmap_layer_destroy(s_eye_1_b);
  bitmap_layer_destroy(s_eye_2_a);
  bitmap_layer_destroy(s_eye_2_b);
  bitmap_layer_destroy(s_eye_3_a);
  bitmap_layer_destroy(s_eye_3_b);
  bitmap_layer_destroy(s_eye_4_a);
  bitmap_layer_destroy(s_eye_4_b);
  bitmap_layer_destroy(s_eye_5_a);
  bitmap_layer_destroy(s_eye_5_b);
  bitmap_layer_destroy(s_eye_6_a);
  bitmap_layer_destroy(s_eye_6_b);
  bitmap_layer_destroy(s_eye_7_a);
  bitmap_layer_destroy(s_eye_7_b);
  bitmap_layer_destroy(s_eye_8_a);
  bitmap_layer_destroy(s_eye_8_b);
  bitmap_layer_destroy(s_eye_9_a);
  bitmap_layer_destroy(s_eye_9_b);
  bitmap_layer_destroy(s_eye_10_a);
  bitmap_layer_destroy(s_eye_10_b);
  bitmap_layer_destroy(s_eye_11_a);
  bitmap_layer_destroy(s_eye_11_b);
  bitmap_layer_destroy(s_eye_12_a);
  bitmap_layer_destroy(s_eye_12_b);
  bitmap_layer_destroy(s_minute);
  
  bitmap_layer_destroy(s_edge_mask);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  struct tm* t = tick_time;
  hour = (t->tm_hour)%12;
  minute = (t->tm_min);
  if (minute != lastMinute){
    lastMinute = minute;
    moveMinute();
  }
  update_time();
}
  
static void init() {
  s_main_window = window_create();
  frame = 0;
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  window_stack_push(s_main_window, true);
  tick_timer_service_subscribe(SECOND_UNIT, tick_handler);
}

static void deinit() {
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
