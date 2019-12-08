#include <glimac/glm.hpp>
#include "../include/glimac/TrackballCamera.hpp"
#include <math.h>

namespace glimac {

	TrackballCamera::TrackballCamera(){
			m_fDistance = 5.f;
			m_fAngleX = 0.f;
			m_fAngleY = 0.f;
		}

	//Méthodes
	void TrackballCamera::moveFront(const float &delta){
		m_fDistance += delta;
	}
	void TrackballCamera::rotateLeft(const float &degrees){
		m_fAngleY += degrees;
	}
	void TrackballCamera::rotateUp(const float &degrees){
		m_fAngleX += degrees;
	}

	glm::mat4 TrackballCamera::getViewMatrix() const{
		glm::mat4 VMatrix = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, m_fDistance));
		VMatrix = glm::rotate(VMatrix, glm::radians(m_fAngleX), glm::vec3(1.f, 0.f, 0.f));
		VMatrix = glm::rotate(VMatrix, glm::radians(m_fAngleY), glm::vec3(0.f, 1.f, 0.f));
		return VMatrix;
	}
}