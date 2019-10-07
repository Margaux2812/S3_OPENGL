#version 330 core

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vFragColor;

mat3 translate(float tx, float ty){
	return mat3(
		vec3(1, 0, 0),
		vec3(0, 1, 0),
		vec3(tx, ty, 1)
	);
}

mat3 scale(float sx, float sy){
	return mat3(
		vec3(sx, 0, 0),
		vec3(0, sy, 0),
		vec3(0, 0, 1)
	);
}

mat3 rotate(float a){
	float theta = radians(a);
	return mat3(
		vec3(cos(theta), sin(theta), 0),
		vec3(-sin(theta), cos(theta), 0),
		vec3(0, 0, 1)
	);
}

void main() {
  vFragColor = aVertexColor;
  vec2 positionFinale;
  /*			Translation de (0.5, 0.5)
  positionFinale = aVertexPosition.xy + vec2(0.5, 0.5);
  				Avec les fonctions
  positionFinale = (translate(0.5, 0.5) * vec3(aVertexPosition, 1)).xy;
  */

  /*			Doubler la taille du triangle
  positionFinale = aVertexPosition.xy * 2;
  				Avec les fonctions
  positionFinale = (scale(2, 2) * vec3(aVertexPosition, 1)).xy;
  */

  /*			Doubler la taille sur l'axe des x et reduire de 2 sur l'axe des y
  positionFinale = aVertexPosition * vec2(2, 0.5);
  				Avec les fonctions
  positionFinale = (scale(2, 0.5) * vec3(aVertexPosition, 1)).xy;
  */

  positionFinale = (rotate(45) * vec3(aVertexPosition, 1)).xy;

  gl_Position = vec4(positionFinale, 0, 1);
};