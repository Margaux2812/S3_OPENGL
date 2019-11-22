#version 330

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec2 aVertexCoord;

out vec2 vVertexCoord;

uniform mat3 uModelMatrix;

void main() {
    vVertexCoord = aVertexCoord;

    vec2 positionFinale = (uModelMatrix * vec3(aVertexPosition, 1)).xy;
    gl_Position = vec4(positionFinale, 0, 1);
}
