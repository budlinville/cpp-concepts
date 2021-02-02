#pragma once

class Box {
	private:
		int m_length;
		int m_width;
		int m_height;

	public: 
		Box(int length, int width, int height);
		// variable names are optional
		Box(int);
		~Box();

		void setLength(int);
		int getLength();

		void setWidth(int);
		int getWidth();

		void setHeight(int);
		int getHeight();

		int getVolume();
		int getSurfaceArea();
};