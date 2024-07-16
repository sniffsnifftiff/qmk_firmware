#define SCREEN_WIDTH 32
#define SCREEN_HEIGHT 128
#define CHAR_HEIGHT 8

const char scroll_text[] = "Hubert co sie dzieje!";
char reversed_text[sizeof(scroll_text)];

void reverse_string(const char *src, char *dst) {
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        dst[i] = src[len - i - 1];
    }
    dst[len] = '\0'; // Null-terminate the reversed string
}

const int text_height = CHAR_HEIGHT * strlen(scroll_text);

int16_t text_y = -text_height;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    reverse_string(scroll_text, reversed_text); // Reverse the string at initialization
    return OLED_ROTATION_270;
}

void oled_write_vertical(const char *data, uint8_t x, uint8_t y_start) {
    uint8_t y = y_start; // Starting y position
    while (*data) {
        oled_set_cursor(x, y);   // Set the cursor position
        oled_write_char(*data, false); // Write the character
        data++;  // Move to the next character in the string
        y++;     // Move to the next line
    }
}

// void update_text_position(void) {
//     text_y += 9; // Adjust the speed by changing the increment value
//     if (text_y > screen_height) {
//         text_y = -text_height;
//     }
// }

// void draw_text(void) {
//     oled_clear();
//     for (int i = 0; i < strlen(reversed_text); i++) {
//         int cursor_y = text_y + (i * CHAR_HEIGHT);
//         if (cursor_y >= 0 && cursor_y < SCREEN_HEIGHT) {
//             oled_set_cursor(0, cursor_y / CHAR_HEIGHT);
//             oled_write_char(reversed_text[i], false);
//         }
//     }
//     oled_write_ln(scroll_text, false);
// }
