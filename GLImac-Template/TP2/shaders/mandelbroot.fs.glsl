#version 330

in vec2 vFragPosition;

out vec3 fFragColor;

vec2 complexSqr(vec2 z){
	vec2 result = vec2(z.x*z.x - z.y*z.y, 2*z.x*z.y);

	return result;
}

vec2 next(vec2 z){
	return complexSqr(z) + vFragPosition;
}

void main() {
	bool isSet = false;
    int Nmax = 30;
    vec2 z = vFragPosition;

    for(int i=0; i<Nmax; i++){
    	if(length(z) > 2){
    		fFragColor = vec3(float(i)/Nmax, float(i)/Nmax, float(i)/Nmax);
    		isSet = true;
    		break;
    	}
    	z = next(z);
    }

    if(!isSet){
    	fFragColor = vec3(0., 0., 0.);
    }
}