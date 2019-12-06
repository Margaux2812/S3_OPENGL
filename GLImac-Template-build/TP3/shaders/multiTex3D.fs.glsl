#version 330

in vec2 vtexCoords;

out vec3 fFragColor;

uniform sampler2D uEarthTexture;
uniform sampler2D uCloudTexture;

void main() {
    fFragColor = texture(uEarthTexture, vtexCoords).xyz + texture(uCloudTexture, vtexCoords).xyz;
}
