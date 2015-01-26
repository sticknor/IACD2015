#include <pebble.h>
  
static Window *s_main_window;

// Anaimation Values
int frame;

// Background
static BitmapLayer *s_background_layer;
static GBitmap *s_background_bitmap;

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

// Pupil Bitmaps
static GBitmap *s_pupil;
static BitmapLayer *s_minute; 

// Update Time and Animate

static void update_time() {
  BitmapLayer *hourEye_a = s_eye_2_a;
  BitmapLayer *hourEye_b = s_eye_2_b;

  if (frame == 0){
    frame = 1;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_0_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_0_b);
  }
  else if(frame ==1){
    frame = 2;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_1_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_1_b);
  }
  else if(frame ==2){
    frame = 3;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_2_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_2_b);
  }
  else if(frame ==3){
    frame = 4;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_3_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_3_b);
  }
  else if(frame ==4){
    frame = 5;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_4_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_4_b);
  }
  else if(frame ==5){
    frame = 6;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_5_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_5_b);
  }
  else{
    frame = 0;
    bitmap_layer_set_bitmap(hourEye_a, s_frame_6_a);
    bitmap_layer_set_bitmap(hourEye_b, s_frame_6_b);
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
    
  s_pupil = gbitmap_create_with_resource(RESOURCE_ID_Pupil);

  
  // Initialize and Size Layers
  s_background_layer = bitmap_layer_create(GRect(0, 0, 144, 168));

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

  s_minute = bitmap_layer_create(GRect(48, 0, 48, 42));


  //Match Bitmaps to Layers and Add Layer to Window
  bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_background_layer));
  
  bitmap_layer_set_bitmap(s_minute, s_pupil);
  bitmap_layer_set_compositing_mode (s_minute, GCompOpAnd);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_minute));  
   
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

  
  // Make sure the time is displayed from the start
  update_time();
}

static void main_window_unload(Window *window) {
  // Destroy GBitmaps
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
  gbitmap_destroy(s_pupil);

  // Destroy BitmapLayer
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
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}
  
static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();
  frame = 0;
  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);
  
  // Register with TickTimerService
  tick_timer_service_subscribe(SECOND_UNIT, tick_handler);
}

static void deinit() {
  // Destroy Window
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
