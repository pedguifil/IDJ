#include "Vec2.h"
#include "Game.h"

Vec2::Vec2() {
	x = 0;
	y = 0;
}

Vec2::Vec2(float cordX, float cordY) {
	x = cordX;
	y = cordY;
}
void Vec2::operator=(Vec2 vetor) {
	x = vetor.x;
	y = vetor.y;
}
void Vec2::operator+=(Vec2 vetor) {
	x += vetor.x;
	y += vetor.y;
}
void Vec2::operator-=(Vec2 vetor) {
	x -= vetor.x;
	y -= vetor.y;
}
void Vec2::operator*=(Vec2 vetor) {
	x *= vetor.x;
	y *= vetor.y;
}
void Vec2::operator/=(Vec2 vetor) {
	x /= vetor.x;
	x /= vetor.y;
}
bool Vec2::operator==(Vec2 vetor) {
	return (x == vetor.x && y == vetor.y);
}

void Vec2::operator=(float escalar) {
	x = escalar;
	y = escalar;
}
void Vec2::operator+=(float escalar) {
	x += escalar;
	y += escalar;
}
void Vec2::operator-=(float escalar) {
	x -= escalar;
	y -= escalar;
}
void Vec2::operator*=(float escalar) {
	x *= escalar;
	y *= escalar;
}
void Vec2::operator/=(float escalar) {
	x /= escalar;
	y /= escalar;
}
float Vec2::Magnitude() {
	return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}
Vec2 Vec2::Center() {
	Vec2 centro;

	centro.x = x / 2;
	centro.y = y / 2;
	return centro;
}
Vec2& Vec2::Unit() {
	x /= Magnitude();
	y /= Magnitude();
	return *this;
}
float Vec2::Distance(Vec2 v) {
	return std::sqrt(std::pow(v.x - x, 2) + std::pow(v.y - y, 2));
}
// Inclinação: 0 para 90° e 1 para 0°
Vec2 Vec2::AngleX(Vec2 v) {
	Vec2 angles(std::cos(ToAngle(v)), std::sin(ToAngle(v)));
	return angles;
}
float Vec2::ToAngle(Vec2 v) {
	float teta = std::atan2((v.y - y), (v.x - x));
	return teta;
}
bool Vec2::NearBy(Vec2 v) {
	return (x <= v.x + 10 && x >= v.x - 10) && (y <= v.y + 10 && y >= v.y - 10);
}
Vec2 Vec2::GetRotated(float angulo) {
	return Vec2((x * cos(angulo)) - (y * sin(angulo)), (y * cos(angulo)) + (x * sin(angulo)));
}

Vec2 Vec2::operator+(const Vec2& v) const {
	return Vec2(x + v.x, y + v.y);
}

Vec2 Vec2::operator-(const Vec2& v) const {
	return Vec2(x - v.x, y - v.y);
}

Vec2 Vec2::operator*(const float v) const {
	return Vec2(x * v, y * v);
}