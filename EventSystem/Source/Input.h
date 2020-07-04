#pragma once
#include <utility>

namespace Prism
{
	class Input     //Singleton
	{
	public:
		inline static bool IsKeyPressed(int keyCode) { return s_Instance->IsKeyPressedImplementation(keyCode); }
		

	private:
		static Input* s_Instance;  //Pointer to Input. 

	protected:
		virtual bool IsKeyPressedImplementation(int keyCode) = 0;
		virtual bool IsMouseButtonPressedImplementation(int button) = 0;
		virtual std::pair<float, float> GetMousePositionImplementation() = 0;
		virtual float GetMouseXImplementation() = 0;
		virtual float GetMouseYImplementation() = 0;
	};

}