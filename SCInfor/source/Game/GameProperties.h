//  _____________________________________________
// | GameProperties.h - class definition         |
// | Jack Flower -  July 2012                    |
// |_____________________________________________|
//

#ifndef H_GAME_PROPERTIES_JACK
#define H_GAME_PROPERTIES_JACK

#include "../Utilities/Singleton/CSingleton.h"
#include "../XML/Xml.h"

#define gGameProperties GameProperties::GetSingleton()

using namespace xml;

namespace game
{
	///
	///Klasa reprezentuje opcje gry
	///
	class GameProperties : public CSingleton<GameProperties>
	{
	public:

		///
		///Konstruktor domyślny
		///
		GameProperties(void);

		///
		///Konstruktor kopiujący
		///
		///@param GamePropertiesCopy - stała referencja na obiekt klasy GameProperties
		///
		GameProperties(const GameProperties & GamePropertiesCopy);

		///
		///Destruktor
		///
		~GameProperties(void);

		///
		///Metoda zwraca szerokość okna
		///
		unsigned int getWidth();

		///
		///Metoda ustawia szerokość okna
		///
		///@param width - szerokość okna
		///
		void setWidth(unsigned int width);

		///
		///Metoda zwraca wysokość okna
		///
		unsigned int getHeight();

		///
		///Metoda ustawia wysokość okna
		///
		///@param height - wysokość okna
		///
		void setHeight(unsigned int height);

		///
		///Metoda zwraca głebię kolorów
		///
		unsigned int getBitsPerPixel();

		///
		///Metoda ustawia głębię kolorów
		///
		///@param bits_per_pixel_depth - głębia kolorów
		///
		void setBitsPerPixel(unsigned int bits_per_pixel_depth);

		///
		///Metoda zwraca tryb pełnoekranowy
		///
		bool isFullscreen();

		///
		///Metoda ustawia tryb pełnoekranowy
		///
		///@param fullscreen - flaga trybu pełnoekranowego
		///
		void setFullscreen(bool fullscreen);

		///
		///Metora zwraca tryb synchronizacji pionowej
		///
		bool isVSync();

		///
		///Metoda ustawia tryb synchronizacji pionowej
		///
		///@param vsync - flaga trybu synchronizacji pionowej
		///
		void setVSync(bool vsync);

		///
		///Metoda zwraca głośność dźwięku
		///
		float getSoundVolume();

		///
		///Metoda ustawia głośność dźwięku
		///
		///@param sound_volume - głośność dźwięku
		///
		void setSoundVolume(float sound_volume);

		///
		///Metoda zwraca głośność muzyki
		///
		float getMusicVolume();

		///
		///Metoda ustawia głośność muzyki
		///
		///@param music_volume - głośność muzyki
		///
		void setMusicVolume(float music_volume);

		///
		///Metoda zwraca nazwę okna
		///
		const std::string getWindowName() const;

		///
		///Metoda ustawia nazwę okna
		///
		///@param windows_name - nazwa okna
		///
		const void setWindowName(std::string & windows_name);

		///
		///Metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string &  name);

		///
		///Metoda ładująca dane z xml
		///
		///@param xml - referencja na obiekt klasy Xml
		///
		bool load(Xml & xml);

		///
		///Metoda tworzy okno
		///
		void updateWindow();

	protected:

		///
		///Wirtualna metoda czyszcząca singleton
		///
		virtual void cleanup();

	private:

		unsigned int m_width; //szerokość okna
		unsigned int m_height; //wysokość okna
		unsigned int m_bits_per_pixel_depth; //głębia kolorów - poczytać www.sfml-dev.org
		bool m_fullscreen; //flaga - FullScreen
		bool m_vsync; //flaga - synchronizacja pionowa - poczytać www.sfml-dev.org
		float m_sound_volume; //głośność dźwięku
		float m_music_volume; //głośność muzyki
		std::string m_windows_name; //nazwa okna
		float m_time_step; //wartość kroku czasowego
		//time step: 1.f/60.f; //60 aktualizacji na sekundę (niektóre gotowe framework'i)
		//time step: 1.f/40.f; //40 aktualizacji na sekundę (warto ją zastosować)
		//time step: 1.f/30.f; //30 aktualizacji na sekundę (optymalna - stosowana)
	};
}//namespace game
#endif //H_GAME_PROPERTIES_JACK
