#ifndef _VEC2_H_
#define _VEC2_H_
#include <cmath>

class Vec2 {
public:
	float x;
	float y;

	Vec2();
	Vec2(float, float);
	void operator=(Vec2); // THIS = vec2
	void operator+=(Vec2); // THIS + vec2
	void operator-=(Vec2); // THIS - vec2
	void operator*=(Vec2); // THIS * vec2
	void operator/=(Vec2); // THIS / vec2
	bool operator==(Vec2); // (bool) if THIS == vec2
	void operator=(float); // THIS = escalar
	void operator+=(float); // THIS + escalar
	void operator-=(float); // THIS - escalar
	void operator*=(float); // THIS * escalar
	void operator/=(float); // THIS / escalar
	Vec2 operator+(const Vec2& v) const;
	Vec2 operator-(const Vec2& v) const;
	Vec2 operator*(const float v) const;
	float Magnitude(); // Norma, tamanho
	Vec2 Center(); // Coordenadas do centro de (0, 0) at� THIS
	Vec2& Unit(); // Vetor unit�rio na mesma dire��o e sentido que THIS
	float Distance(Vec2); // Dist�ncia entre THIS e Vec2
	Vec2 AngleX(Vec2); // Inclina��o entre [THIS, vec2] em rela��o ao eixo X
	float ToAngle(Vec2); // �ngulo entre dois pontos e o eixo X
	Vec2 sum(const Vec2& v) const;
	Vec2 minus(const Vec2& v) const;
	Vec2 times(const float v) const;
	bool NearBy(Vec2);
	Vec2 GetRotated(float ang);
};


#endif