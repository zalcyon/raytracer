#include "Vector.hpp"
#include "Line.hpp"
#include "Color.hpp"
#include "Intersection.hpp"

#ifndef RT_LIGHT_INCLUDED
#define RT_LIGHT_INCLUDED

namespace rt {

	class Light {
	private:
		Vector _position;
		Color _ambient;
		Color _diffuse;
		Color _specular;
		double _intensity;

	public:
		Light(Vector const& pos, Color const& ambient, Color const& diffuse, Color const& specular,
			double intensity) {
			_position = Vector(pos);
			_ambient = Color(ambient);
			_diffuse = Color(diffuse);
			_specular = Color(specular);
			_intensity = intensity;
		}



		inline Vector& position() {
			return _position;
		}

		inline Color& ambient() {
			return _ambient;
		}

		inline Color& diffuse() {
			return _diffuse;
		}

		inline Color& specular() {
			return _specular;
		}

		inline double intensity() {
			return _intensity;
		}
	};
}

#endif
