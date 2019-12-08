#pragma once
#include <glimac/glm.hpp>

namespace glimac {

	class FreeflyCamera{
	private :
		glm::vec3 m_Position;
		float m_fPhi;
		float m_fTheta;
		glm::vec3 m_FrontVector;
		glm::vec3 m_LeftVector;
		glm::vec3 m_UpVector;

	public:
		//Constructeur
		FreeflyCamera();

		//Méthodes
		void computeDirectionVectors(glm::vec3 &m_FrontVector, glm::vec3 &m_LeftVector, glm::vec3 &m_UpVector, const float m_fPhi, const float m_fTheta);
		void moveLeft(const float t);
		void moveFront(const float t);
		void rotateLeft(const float degrees);
		void rotateUp(const float degrees);
		glm::mat4 getViewMatrix() const;
	};
}