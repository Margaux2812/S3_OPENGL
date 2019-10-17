#version 330

in vec3 vColor;
in vec2 vPosition;

out vec3 fFragColor;

void main() {

	float alpha = 3.; //Régule le blanc
	float beta = 28.;
	float distance = distance(vec2(0., 0.), vPosition);
	float attenuation = alpha * exp(-beta * distance * distance);
    fFragColor = vColor * attenuation;
}

