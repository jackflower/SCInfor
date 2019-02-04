//  ___________________________________________
// | CClippedSprite.cpp - class implementation |
// | Jack Flower February 2012                 |
// |___________________________________________|
//

#include "CClippedSprite.h"
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
	RTTI_IMPL_NOPARENT(CClippedSprite);

	//Konstruktor domyœlny
	CClippedSprite::CClippedSprite()
	:
		m_clip_plane_enabled(false)
	{
	}

	//Metoda w³¹cza przycinanie
	void CClippedSprite::EnableClipPlane()
	{ 
		m_clip_plane_enabled = true;
	}

	//Metoda wy³¹cza przycinanie
	void CClippedSprite::DisableClipPlane()
	{ 
		m_clip_plane_enabled = false;
	}


	//Sprawdzamy, czy punkt znajduje siê ('nad', 'zawiera siê w', 'nale¿y do') p³aszczyzn¹
	inline bool TestPoint(float a, float b, float c, float x, float y)
	{
		return (a * x + b * y + c) > 0.0f;//równanie prostej
	}

	////Wirtualna metoda renderingu
	//void CClippedSprite::Render(sf::RenderTarget &renderTarget) const
	//{
	//	sf::Vector2f	vertex[5];			//tablica na piêæ wierzcho³ków
	//	sf::Vector2f	uv[5];				//tablica na piêæ wierzcho³ków
	//	unsigned int	vertex_count = 0;	//licznik wierzcho³ków

	//	//Tworzymy wierzcho³ki dla prostok¹ta [0-1,0-1] przyciêtego prost¹-p³aszczyzn¹

	//	if (m_clip_plane_enabled)//jeœli flaga pozwala generujemy wspó³rzêdne przyciêtego prostok¹ta
	//	{
	//		//Sprawdzamy, czy punkty znajduje siê 'nad' p³aszczyzn¹
	//		bool leftup		= TestPoint(m_A, m_B, m_C, 0.0f, 0.0f);
	//		bool rightup	= TestPoint(m_A, m_B, m_C, 1.0f, 0.0f);
	//		bool rightbot	= TestPoint(m_A, m_B, m_C, 1.0f, 1.0f);
	//		bool leftbot	= TestPoint(m_A, m_B, m_C, 0.0f, 1.0f);

	//		// lewy górny róg
	//		if (leftup)					vertex[vertex_count++] = sf::Vector2f(0.0f,0.0f);
	//		// przeciêcie clipplane		- górny bok => dodajemy punkt przeciêcia
	//		if (leftup != rightup)		vertex[vertex_count++] = sf::Vector2f(-m_C/m_A,0.0f);
	//									//zwiêkszamy licznik wiercho³ków
	//		
	//		// prawy górny róg
	//		if (rightup)				vertex[vertex_count++] = sf::Vector2f(1.0f,0.0f);
	//		// przeciêcie clipplane		- prawy bok => dodajemy punkt przeciêcia
	//		if (rightup != rightbot)	vertex[vertex_count++] = sf::Vector2f(1.0f,(-m_C-m_A)/m_B);
	//									//zwiêkszamy licznik wiercho³ków
	//		
	//		// prawy dolny róg
	//		if (rightbot)				vertex[vertex_count++] = sf::Vector2f(1.0f,1.0f);
	//		// przeciêcie clipplane		- dolny bok => dodajemy punkt przeciêcia
	//		if (rightbot != leftbot)	vertex[vertex_count++] = sf::Vector2f((-m_C-m_B)/m_A,1.0f);
	//									//zwiêkszamy licznik wiercho³ków
	//		
	//		// lewy dolny róg
	//		if (leftbot)				vertex[vertex_count++] = sf::Vector2f(0.0f,1.0f);
	//		// przeciêcie clipplane		- lewy bok => dodajemy punkt przeciêcia
	//		if (leftbot != leftup)		vertex[vertex_count++] = sf::Vector2f(0.0f,-m_C/m_B);		
	//									//zwiêkszamy licznik wiercho³ków
	//	}
	//	else
	//	{	//Jeœli flaga nie pozwala na przyciêcie - pozostawiamy wierzcho³ki bez zmian
	//		vertex[vertex_count++] = sf::Vector2f(0.0f,0.0f);
	//		vertex[vertex_count++] = sf::Vector2f(1.0f,0.0f);
	//		vertex[vertex_count++] = sf::Vector2f(1.0f,1.0f);
	//		vertex[vertex_count++] = sf::Vector2f(0.0f,1.0f);
	//	}

	//	//jeœli licznik wierzcho³ków przekroczy 5, to coœ nie gra (np. precyzja floatow)
	//	assert(vertex_count <= 5);

	//	//Obliczamy wielkoœæ sprite'a
	//	float sprite_width		= static_cast<float>(GetSubRect().GetWidth());
	//	float sprite_height		= static_cast<float>(GetSubRect().GetHeight());

	//	//jeœli sprite ma ustawion¹ teksturê sf::Image
	//	if (GetImage())
	//	{
	//		GetImage()->Bind();//bindujemy teksturê, aby dopasowaæ do niej rozmiar sprite'a

	//		sf::FloatRect	texture_coordinate	= GetImage()->GetTexCoords(GetSubRect());
	//		float			texture_width		= texture_coordinate.GetWidth();
	//		float			texture_height		= texture_coordinate.GetHeight();

	//		//Generujemy wierzcho³ki prostok¹ta i skalujemy sprite'a do jego rozmiarow
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
