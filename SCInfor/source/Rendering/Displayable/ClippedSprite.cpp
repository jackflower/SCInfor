//  ___________________________________________
// | ClippedSprite.cpp - class implementation |
// | Jack Flower February 2012                 |
// |___________________________________________|
//

#include "ClippedSprite.h"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <assert.h>

//#ifdef PLATFORM_MACOSX
//#include <gl.h>
//#else
//#include <GL/gl.h>
//#endif

namespace displayable
{
	RTTI_IMPL_NOPARENT(ClippedSprite);

	//Konstruktor domyślny
	ClippedSprite::ClippedSprite()
	:
		m_clip_plane_enabled(false)
	{
	}

	//Metoda włącza przycinanie
	void ClippedSprite::enableClipPlane()
	{ 
		m_clip_plane_enabled = true;
	}

	//Metoda wyłącza przycinanie
	void ClippedSprite::disableClipPlane()
	{ 
		m_clip_plane_enabled = false;
	}


	//Sprawdzamy, czy punkt znajduje się ('nad', 'zawiera się w', 'należy do') płaszczyzną
	inline bool TestPoint(float a, float b, float c, float x, float y)
	{
		return (a * x + b * y + c) > 0.0f;//równanie prostej
	}

	////Wirtualna metoda renderingu
	//void ClippedSprite::Render(sf::RenderTarget &renderTarget) const
	//{
	//	sf::Vector2f	vertex[5];			//tablica na pięć wierzchołków
	//	sf::Vector2f	uv[5];				//tablica na pięć wierzchołków
	//	unsigned int	vertex_count = 0;	//licznik wierzchołków

	//	//Tworzymy wierzchołki dla prostokąta [0-1,0-1] przyciętego prostą-płaszczyzną

	//	if (m_clip_plane_enabled)//jeśli flaga pozwala generujemy współrzędne przyciętego prostokąta
	//	{
	//		//Sprawdzamy, czy punkty znajduje się 'nad' płaszczyzną
	//		bool leftup		= TestPoint(m_A, m_B, m_C, 0.0f, 0.0f);
	//		bool rightup	= TestPoint(m_A, m_B, m_C, 1.0f, 0.0f);
	//		bool rightbot	= TestPoint(m_A, m_B, m_C, 1.0f, 1.0f);
	//		bool leftbot	= TestPoint(m_A, m_B, m_C, 0.0f, 1.0f);

	//		// lewy górny róg
	//		if (leftup)					vertex[vertex_count++] = sf::Vector2f(0.0f,0.0f);
	//		// przecięcie clipplane		- górny bok => dodajemy punkt przecięcia
	//		if (leftup != rightup)		vertex[vertex_count++] = sf::Vector2f(-m_C/m_A,0.0f);
	//									//zwiększamy licznik wierchołków
	//		
	//		// prawy górny róg
	//		if (rightup)				vertex[vertex_count++] = sf::Vector2f(1.0f,0.0f);
	//		// przecięcie clipplane		- prawy bok => dodajemy punkt przecięcia
	//		if (rightup != rightbot)	vertex[vertex_count++] = sf::Vector2f(1.0f,(-m_C-m_A)/m_B);
	//									//zwiększamy licznik wierchołków
	//		
	//		// prawy dolny róg
	//		if (rightbot)				vertex[vertex_count++] = sf::Vector2f(1.0f,1.0f);
	//		// przecięcie clipplane		- dolny bok => dodajemy punkt przecięcia
	//		if (rightbot != leftbot)	vertex[vertex_count++] = sf::Vector2f((-m_C-m_B)/m_A,1.0f);
	//									//zwiększamy licznik wierchołków
	//		
	//		// lewy dolny róg
	//		if (leftbot)				vertex[vertex_count++] = sf::Vector2f(0.0f,1.0f);
	//		// przecięcie clipplane		- lewy bok => dodajemy punkt przecięcia
	//		if (leftbot != leftup)		vertex[vertex_count++] = sf::Vector2f(0.0f,-m_C/m_B);		
	//									//zwiększamy licznik wierchołków
	//	}
	//	else
	//	{	//Jeśli flaga nie pozwala na przycięcie - pozostawiamy wierzchołki bez zmian
	//		vertex[vertex_count++] = sf::Vector2f(0.0f,0.0f);
	//		vertex[vertex_count++] = sf::Vector2f(1.0f,0.0f);
	//		vertex[vertex_count++] = sf::Vector2f(1.0f,1.0f);
	//		vertex[vertex_count++] = sf::Vector2f(0.0f,1.0f);
	//	}

	//	//jeśli licznik wierzchołków przekroczy 5, to coś nie gra (np. precyzja floatow)
	//	assert(vertex_count <= 5);

	//	//Obliczamy wielkość sprite'a
	//	float sprite_width		= static_cast<float>(GetSubRect().GetWidth());
	//	float sprite_height		= static_cast<float>(GetSubRect().GetHeight());

	//	//jeśli sprite ma ustawioną teksturę sf::Image
	//	if (GetImage())
	//	{
	//		GetImage()->Bind();//bindujemy teksturę, aby dopasować do niej rozmiar sprite'a

	//		sf::FloatRect	texture_coordinate	= GetImage()->GetTexCoords(GetSubRect());
	//		float			texture_width		= texture_coordinate.GetWidth();
	//		float			texture_height		= texture_coordinate.GetHeight();

	//		//Generujemy wierzchołki prostokąta i skalujemy sprite'a do jego rozmiarow
	//		for (unsigned int i = 0; i < vertex_count; i++)
	//		{
	//			uv[i].x		= texture_coordinate.Left	+ vertex[i].x * texture_width;
	//			uv[i].y		= texture_coordinate.Top	+ vertex[i].y * texture_height;
	//			vertex[i].x *= sprite_width;
	//			vertex[i].y *= sprite_height;
	//		}

	//		glEnableClientState	( GL_VERTEX_ARRAY );
	//		glVertexPointer		( 2, GL_FLOAT, 0, vertex );
	//		glEnableClientState	( GL_TEXTURE_COORD_ARRAY );
	//		glTexCoordPointer	( 2, GL_FLOAT, 0, uv );
	//		glDrawArrays		( GL_TRIANGLE_FAN, 0, vertex_count );
	//		glDisableClientState( GL_VERTEX_ARRAY );
	//		glDisableClientState( GL_TEXTURE_COORD_ARRAY );
	//	}
	//	else
	//	{
	//		//Skalujemy sprite'a do jego rozmiarów - sprite'e nie ma tekstury
	//		for (unsigned i = 0; i < vertex_count; i++)
	//		{
	//			vertex[i].x *= sprite_width;
	//			vertex[i].y *= sprite_height;
	//		}

	//		glDisable			( GL_TEXTURE_2D);
	//		glEnableClientState	( GL_VERTEX_ARRAY );
	//		glVertexPointer		( 2, GL_FLOAT, 0, vertex );
	//		glDrawArrays		( GL_TRIANGLE_FAN, 0, vertex_count );
	//		glDisableClientState( GL_VERTEX_ARRAY );
	//	}
	//}
} //namespace displayable
