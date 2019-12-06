#version 330

in vec2 vtexCoords;

out vec3 fFragColor;

uniform sampler2D uTexture;

void main() {
    fFragColor = texture(uTexture, vtexCoords).xyz;
}
