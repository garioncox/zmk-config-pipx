#include <zephyr/kernel.h>
#include "profile.h"

#define PROFILE_COUNT 3
#define PROFILE_DOT_SIZE 5
#define PROFILE_DOT_SPACING 9
#define PROFILE_ROW_X 22
#define PROFILE_ROW_Y 50

static void draw_profile_dot(lv_obj_t *canvas, int index, bool active) {
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_rect_dsc_init(&rect_dsc);
    rect_dsc.radius = LV_RADIUS_CIRCLE;
    rect_dsc.border_color = LVGL_FOREGROUND;
    rect_dsc.border_width = 1;
    rect_dsc.border_opa = LV_OPA_COVER;
    rect_dsc.bg_color = LVGL_FOREGROUND;
    rect_dsc.bg_opa = active ? LV_OPA_COVER : LV_OPA_TRANSP;

    int x = PROFILE_ROW_X + index * PROFILE_DOT_SPACING;
    lv_canvas_draw_rect(canvas, x, PROFILE_ROW_Y, PROFILE_DOT_SIZE, PROFILE_DOT_SIZE, &rect_dsc);
}

void draw_profile_status(lv_obj_t *canvas, const struct status_state *state) {
    for (int i = 0; i < PROFILE_COUNT; i++) {
        draw_profile_dot(canvas, i, i == state->active_profile_index);
    }
}