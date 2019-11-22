#version 330

in vec2 vCoord;

out vec3 fFragColor;

uniform vec3 uColor;

void main() {
    fFragColor = uColor;
}
