#pragma once

#include <cstdint>

struct SDL_Window;
struct SDL_Surface;

namespace dae
{
	class Scene;

	class Renderer final
	{
	public:
		Renderer(SDL_Window* pWindow);
		~Renderer() = default;

		Renderer(const Renderer&) = delete;
		Renderer(Renderer&&) noexcept = delete;
		Renderer& operator=(const Renderer&) = delete;
		Renderer& operator=(Renderer&&) noexcept = delete;

		void Render(Scene* pScene) const;
		bool SaveBufferToImage() const;
		void CycleLightMode();
		void ToggleShadows() {m_ShadowsEnabled = !m_ShadowsEnabled;}

	private:

		enum class LightingMode
		{
			ObservedArea,
			Radiance,
			BRDF,
			Combined
		};

		LightingMode m_CurrentLightingMode{ LightingMode::Combined };
		bool m_ShadowsEnabled{ false };
		SDL_Window* m_pWindow{};

		SDL_Surface* m_pBuffer{};
		uint32_t* m_pBufferPixels{};

		int m_Width{};
		int m_Height{};
	};
}
