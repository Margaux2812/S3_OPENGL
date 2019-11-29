#version 330

in vec3 vPosition;
in vec3 vNormale;
in vec2 vtexCoords;

out vec3 fFragColor;

void main() {
    fFragColor = normalize(vNormale);
}
