#ifndef SCENE_11_H
#define SCENE_11_H
#include "MatrixStack.h"
#include "Scene.h"
#include "Camera3.h"
#include "Mesh.h"
#include "Light.h"
#include "Material.h"
class Scene13 : public Scene
{
	enum GEOMETRY_TYPE
	{
		GEO_AXES,
		GEO_QUAD,
		GEO_CUBE,
		GEO_CUBE_PURPLE,
		GEO_CUBE_GREEN,
		GEO_CUBE_BROWN,
		GEO_CUBE_WHITE,
		GEO_CUBE_GREY,
		GEO_SPHERE_JOINT,
		GEO_CIRCLE,
		GEO_SPHERE,
		GEO_LIGHTBALL,
		GEO_SPHERE_PEARL,
		GEO_SPHERE_PEARL_INNER,
		GEO_LEFT,
		GEO_RIGHT,
		GEO_TOP,
		GEO_BOTTOM,
		GEO_FRONT,
		GEO_BACK,
		GEO_BLEND,
		GEO_NYP,
		GEO_CHAIR,
		GEO_SHOE,
		GEO_DOORMAN,
		GEO_DART,
		GEO_COTTAGE,
		GEO_TEXT,

		NUM_GEOMETRY,
	};
	enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,
		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,
		U_LIGHTENABLED,
		U_LIGHT0_TYPE,	
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,
		U_NUMLIGHTS,
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,
		U_TEXT_ENABLED,
		U_TEXT_COLOR,

		U_TOTAL,
	};
public:
	Scene13();
	~Scene13();
	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();
private:
	unsigned m_vertexArrayID;
	Mesh *meshList[NUM_GEOMETRY];
	MS modelStack, viewStack, projectionStack;
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];
	Light light[1];
	void RenderMesh(Mesh* mesh, bool enableLight);
	void RenderSkybox();
	float rotateAngle;
	float rotateAngleF;
	float rotateAngleSF;
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderMeshOnScreen(Mesh* mesh, int x, int y, int sizex, int sizey);
	Camera3 camera;
};

#endif