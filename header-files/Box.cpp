// include just copies the entire contents of Box.h and literally pastes it here
#include "Box.h"

Box::Box(int length, int width, int height) {
	m_length = length;
	m_width = width;
	m_height = height;
}

Box::Box(int size) {
	m_length = size;
	m_width = size;
	m_height = size;
}

Box::~Box() {}

void Box::setLength(int length) {
	m_length = length;
}

int Box::getLength() {
	return m_length;
}

void Box::setWidth(int width) {
	m_width = width;
}

int Box::getWidth() {
	return m_width;
}

void Box::setHeight(int height) {
	m_height = height;
}

int Box::getHeight() {
	return m_height;
}

int Box::getVolume() {
	return m_length * m_width * m_height;
}

int Box::getSurfaceArea() {
	return (2 * m_length * m_width)
		+ (2 * m_length * m_height)
		+ (2 * m_width * m_height);
}