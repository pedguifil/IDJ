#include "Rect.h"

Rect::Rect() {

}

Rect::Rect(float cordX, float cordY, float w, float h) {
	x = cordX;
	y = cordY;
	width = w;
	height = h;
}
bool Rect::Contains(Vec2 v) {
	return (v.x < (x + width) && v.x >= x) && (v.y < (y + height) && v.y >= y);
}