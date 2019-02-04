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

	//Konstruktor domy�lny
	CClippedSprite::CClippedSprite()
	:
		m_clip_plane_enabled(false)
	{
	}

	//Metoda w��cza przycinanie
	void CClippedSprite::EnableClipPlane()
	{ 
		m_clip_plane_enabled = true;
	}

	//Metoda wy��cza przycinanie
	void CClippedSprite::DisableClipPlane()
	{ 
		m_clip_plane_enabled = false;
	}


	//Sprawdzamy, czy punkt znajduje si� ('nad', 'zawiera si� w', 'nale�y do') p�aszczyzn�
	inline bool TestPoint(float a, float b, float c, float x, float y)
	{
		return (a * x + b * y + c) > 0.0f;//r�wnanie prostej
	}

	////Wirtualna metoda renderingu
	//void CClippedSprite::Render(sf::RenderTarget &renderTarget) const
	//{
	//	sf::Vector2f	vertex[5];			//tablica na pi�� wierzcho�k�w
	//	sf::Vector2f	uv[5];				//tablica na pi�� wierzcho�k�w
	//	unsigned int	vertex_count = 0;	//licznik wierzcho�k�w

	//	//Tworzymy wierzcho�ki dla prostok�ta [0-1,0-1] przyci�tego prost�-p�aszczyzn�

	//	if (m_clip_plane_enabled)//je�li flaga pozwala generujemy wsp�rz�dne przyci�tego prostok�ta
	//	{
	//		//Sprawdzamy, czy punkty znajduje si� 'nad' p�aszczyzn�
	//		bool leftup		= TestPoint(m_A, m_B, m_C, 0.0f, 0.0f);
	//		bool rightup	= TestPoint(m_A, m_B, m_C, 1.0f, 0.0f);
	//		bool rightbot	= TestPoint(m_A, m_B, m_C, 1.0f, 1.0f);
	//		bool leftbot	= TestPoint(m_A, m_B, m_C, 0.0f, 1.0f);

	//		// lewy g�rny r�g
	//		if (leftup)					vertex[vertex_count++] = sf::Vector2f(0.0f,0.0f);
	//		// przeci�cie clipplane		- g�rny bok => dodajemy punkt przeci�cia
	//		if (leftup != rightup)		vertex[vertex_count++] = sf::Vector2f(-m_C/m_A,0.0f);
	//									//zwi�kszamy licznik wiercho�k�w
	//		
	//		// prawy g�rny r�g
	//		if (rightup)				vertex[vertex_count++] = sf::Vector2f(1.0f,0.0f);
	//		// przeci�cie clipplane		- prawy bok => dodajemy punkt przeci�cia
	//		if (rightup != rightbot)	vertex[vertex_count++] = sf::Vector2f(1.0f,(-m_C-m_A)/m_B);
	//									//zwi�kszamy licznik wiercho�k�w
	//		
	//		// prawy dolny r�g
	//		if (rightbot)				vertex[vertex_count++] = sf::Vector2f(1.0f,1.0f);
	//		// przeci�cie clipplane		- dolny bok => dodajemy punkt przeci�cia
	//		if (rightbot != leftbot)	vertex[vertex_count++] = sf::Vector2f((-m_C-m_B)/m_A,1.0f);
	//									//zwi�kszamy licznik wiercho�k�w
	//		
	//		// lewy dolny r�g
	//		if (leftbot)				vertex[vertex_count++] = sf::Vector2f(0.0f,1.0f);
	//		// przeci�cie clipplane		- lewy bok => dodajemy punkt przeci�cia
	//		if (leftbot != leftup)		vertex[vertex_count++] = sf::Vector2f(0.0f,-m_C/m_B);		
	//									//zwi�kszamy licznik wiercho�k�w
	//	}
	//	else
	//	{	//Je�li flaga nie pozwala na przyci�cie - pozostawiamy wierzcho�ki bez zmian
	//		vertex[vertex_count++] = sf::Vector2f(0.0f,0.0f);
	//		vertex[vertex_count++] = sf::Vector2f(1.0f,0.0f);
	//		vertex[vertex_count++] = sf::Vector2f(1.0f,1.0f);
	//		vertex[vertex_count++] = sf::Vector2f(0.0f,1.0f);
	//	}

	//	//je�li licznik wierzcho�k�w przekroczy 5, to co� nie gra (np. precyzja floatow)
	//	assert(vertex_count <= 5);

	//	//Obliczamy wielko�� sprite'a
	//	float sprite_width		= static_cast<float>(GetSubRect().GetWidth());
	//	float sprite_height		= static_cast<float>(GetSubRect().GetHeight());

	//	//je�li sprite ma ustawion� tekstur� sf::Image
	//	if (GetImage())
	//	{
	//		GetImage()->Bind();//bindujemy tekstur�, aby dopasowa� do niej rozmiar sprite'a

	//		sf::FloatRect	texture_coordinate	= GetImage()->GetTexCoords(GetSubRect());
	//		float			texture_width		= texture_coordinate.GetWidth();
	//		float			texture_height		= texture_coordinate.GetHeight();

	//		//Generujemy wierzcho�ki prostok�ta i skalujemy sprite'a do jego rozmiarow
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
	//		//Skalujemy sprite'a do jego rozmiar�w - sprite'e nie ma tekstury
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
