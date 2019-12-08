#pragma once

#include <math.h>

namespace glimac {

	class TrackballCamera{
	private :
		float m_fDistance;
		float m_fAngleX;
		float m_fAngleY;

	public:
		//Constructeur
		TrackballCamera();

		//Méthodes
		void moveFront(const float &delta);
		void rotateLeft(const float &degrees);
		void rotateUp(const float &degrees);

		glm::mat4 getViewMatrix() const;
	};
}