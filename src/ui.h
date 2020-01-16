#ifndef UI_H
#define UI_H

#include <misc/linmath.h>
#include <stdint.h>

#define GLFW_INCLUDE_GLEXT
#include <GLFW/glfw3.h>

#include <nanovg/nanovg.h>

#include "asset.h"

typedef enum {
  UI_ALIGN_LEFT = 1 << 0,
  UI_ALIGN_CENTER = 1 << 1,
  UI_ALIGN_RIGHT = 1 << 2,

  UI_ALIGN_TOP = 1 << 3,
  UI_ALIGN_MIDDLE = 1 << 4,
  UI_ALIGN_BOTTOM = 1 << 5,
  UI_ALIGN_BASELINE = 1 << 6,
} ui_align;

typedef uint32_t ui_font;

typedef struct {
  uint32_t id;
  ui_font font;

  char *text;
  int text_length, reveal_length;
  int alignment;

  vec2 position, bounds;
  vec4 color, shadow;

  float size, spacing, line_height, shadow_size;

  int use_shadow : 1;
  int use_spacing : 1;
  int use_reveal : 1;
  int use_box : 1;
} ui_text;

typedef struct {
  uint32_t id;
  char *text;
  uint32_t text_alignment;
  ui_font font;
  float font_size;

  vec2 position, size;

  vec4 bg, hover_bg;
  vec4 color, hover_color;
  vec4 border_color, hover_border_color;
  float border_size, border_radius;

  int use_border : 1;
} ui_button;

typedef struct {
  uint32_t id;
  vec2 position, size;

  vec4 bg, hover_bg;
  vec4 border_color, hover_border_color;
  float border_size, border_radius;

  int use_border : 1;
} ui_box;

typedef struct {
  uint32_t id;
  const char **options;
  int option_count, option_display;
  int selected, cursor;

  vec2 position, size;
  vec4 bg, hover_bg;
  vec4 color, hover_color;
  vec4 border_color, hover_border_color;

  vec4 select_bg, select_color;
  vec4 hover_select_bg, hover_Select_color;

  float border_size, border_radius;

  int use_border : 1;
  int showing : 1;
} ui_dropdown;

typedef struct {
  uint32_t id;
  vec2 start, end;
  vec4 color;
  float thickness;
} ui_line;

typedef struct {
  uint32_t id;
  int32_t img_handle;
  vec2 position, size;
  vec4 bg_color, hover_bg_color;
  vec4 color, hover_color;
  uint8_t state;
  int circle : 1;
} ui_option;

typedef enum {
  IMG_GENERATE_MIPMAPS = 1 << 0,
  IMG_REPEATX = 1 << 1,
  IMG_REPEATY = 1 << 2,
  IMG_FLIPY = 1 << 3,
  IMG_PREMUL = 1 << 4,
  IMG_NEAREST = 1 << 5,
} ui_img_flags;

typedef struct {
  uint32_t id;
  vec2 position, size;
  int32_t handle;
} ui_img;

typedef enum {
  UI_TEXT_ALIGN,
  UI_TEXT_COLOR,
  UI_TEXT_SHADOW,
  UI_TEXT_SHADOW_SIZE,
  UI_TEXT_LINE_HEIGHT,
  UI_TEXT_SPACING,

  UI_BUTTON_COLOR,
  UI_BUTTON_BG,
  UI_BUTTON_COLOR_HOVER,
  UI_BUTTON_BG_HOVER,
  UI_BUTTON_BORDER_RADIUS,
  UI_BUTTON_BORDER_COLOR,
  UI_BUTTON_BORDER_SIZE,
  UI_BUTTON_FONT_SIZE,

  UI_CIRCLE_COLOR,
  UI_CIRCLE_BORDER_SIZE,
  UI_CIRCLE_BORDER_COLOR,

  UI_DROPDOWN_FONT_SIZE,
  UI_DROPDOWN_COLOR,
  UI_DROPDOWN_COLOR_HOVER,
  UI_DROPDOWN_BG,
  UI_DROPDOWN_BG_HOVER,

  UI_DROPDOWN_SELECT_COLOR,
  UI_DROPDOWN_SELECT_BG,
  UI_DROPDOWN_SELECT_COLOR_HOVER,
  UI_DROPDOWN_SELECT_BG_HOVER,

  UI_OPTION_IMAGE,
  UI_OPTION_IMAGE_SIZE,
} ui_attrib;

typedef enum {
  UI_NONE = 0,
  UI_INT,
  UI_FLOAT,
  UI_VEC2,
  UI_VEC3,
  UI_VEC4
} ui_attrib_type;

typedef struct {
  ui_attrib attrib;
  ui_attrib_type type;
  void *data;
} ui_attrib_storage;

typedef struct {
  ui_attrib_storage *attribs;
  int count, capacity;
} ui_attrib_map;

typedef enum {
  UI_TEXT = 0,
  UI_BOX,
  UI_BUTTON,
  UI_LINE,
  UI_DROPDOWN,
  UI_OPTION,
  UI_IMAGE
} ui_element_type;

typedef struct {
  void *data;
  ui_element_type type;
} ui_element;

struct ui_leaf;
typedef struct ui_leaf {
  uint32_t uid;
  ui_element element;
  struct ui_leaf *next, *prev;
} ui_leaf;

typedef struct {
  ui_leaf *start, *end;
  ui_leaf *cursor, *raw;
  uint16_t capacity, count;
  int loop : 1;
} ui_tree;

typedef struct {
  vec2 size;
  float pixel_scale;
  NVGcontext *nvg;
  uint32_t global_id;

  ui_attrib_map attribs;

  vec2 mouse_pos;
  int use_mouse : 1;
} ui_ctx;

uint8_t ui_init(vec2 size, float pixel_scale, int use_mouse);
void ui_update(vec2 mouse_pos);
void ui_destroy();

void ui_frame_start();
void ui_frame_end();

void ui_attrib_set(ui_attrib attrib, void *value, ui_attrib_type type);
void ui_attrib_set3f(ui_attrib attrib, float x, float y, float z);
void ui_attrib_set3fv(ui_attrib attrib, vec3 value);
void ui_attrib_set4f(ui_attrib attrib, float x, float y, float z, float w);
void ui_attrib_set4fv(ui_attrib attrib, vec4 value);
void ui_attrib_set2f(ui_attrib attrib, float x, float y);
void ui_attrib_set2fv(ui_attrib attrib, vec2 value);
void ui_attrib_setf(ui_attrib attrib, float value);
void ui_attrib_seti(ui_attrib attrib, int32_t value);

ui_attrib_storage ui_attrib_get(ui_attrib attrib);
int ui_attrib_geti(ui_attrib attrib);
float ui_attrib_getf(ui_attrib attrib);
void ui_attrib_get2f(vec2 dst, ui_attrib attrib);
void ui_attrib_get3f(vec3 dst, ui_attrib attrib);
void ui_attrib_get4f(vec4 dst, ui_attrib attrib);

int8_t ui_attrib_exists(ui_attrib attrib);

ui_font ui_font_get(const char *font_name);
ui_font ui_font_create(asset_t *asset, const char *name);

ui_text ui_text_create(vec2 pos, char *string, float font_size, ui_font font_id,
                       int alignment);
ui_button ui_button_create(vec2 pos, vec2 size, char *text, ui_font font_id);
ui_line ui_line_create(vec2 start, vec2 end, float thickness);
ui_dropdown ui_dropdown_create(vec2 pos, vec2 size, char **options,
                               int option_count);
ui_option ui_option_create(vec2 pos, vec2 size, int state);
ui_box ui_box_create(vec2 pos, vec2 size);
ui_img ui_image_create(asset_t *image_data, ui_img_flags flags, vec2 pos,
                       vec2 size);

void ui_image_destroy(ui_img *img);
void ui_button_destroy(ui_button *button);
void ui_text_destroy(ui_text *text);
void ui_dropdown_destroy(ui_dropdown *dropdown);

void ui_text_bounds(ui_text *text, vec4 bounds);

void ui_test_text(ui_font font);
void ui_text_draw(ui_text *text);
void ui_box_draw(ui_box *box, int8_t focused);
void ui_button_draw(ui_button *button, int8_t focused);
void ui_dropdown_draw(ui_dropdown *dropdown, int8_t focused);
void ui_line_draw(ui_line *line);
void ui_option_draw(ui_option *option, int8_t focused);
void ui_image_draw(ui_img *img);

ui_tree ui_tree_create(ui_element *root, uint16_t capacity);
void ui_tree_destroy(ui_tree *tree);
uint32_t ui_tree_add(ui_tree *tree, void *data, ui_element_type type);
uint32_t ui_tree_get_cursor_id(ui_tree *tree);

uint32_t ui_tree_next(ui_tree *tree);
uint32_t ui_tree_prev(ui_tree *tree);

void ui_tree_draw(ui_tree tree);

#endif
