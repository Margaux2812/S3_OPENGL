#version 330

in vec2 vCoordTex;

out vec3 fFragColor;

uniform sampler2D uTexture;

void main() {
    fFragColor = texture(uTexture, vCoordTex).xyz;
}
