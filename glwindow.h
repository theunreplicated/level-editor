#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>
#include "gl_opengl_window.h"
#include <qglshaderprogram.h>
#include <qopenglshaderprogram.h>
#include <qopenglpaintdevice.h>
/*
GLwidget,nur rendering
Funktionswweise inspieriert von Original example hellogl_es2
*/
/*
class GLWidget:public QGLWidget{
Q_OBJECT
public:
    GLWidget(QWidget*parent=0);
    ~GLWidget();
void initializeGL ();//TODO:vllt. auf protected setzen
void GLWidget::openglINIT();
private:
	QGLShaderProgram program;
	int shader_positionLoc,shader_texCoordLoc,shader_textureLoc;
	GLuint CreateSimpleTexture2D();
	GLuint texture_id;
	 QOpenGLContext *m_context;
    QOpenGLPaintDevice *m_device;
};*/

class GLWindow : public OpenGLWindow
{
public:
    GLWindow();

    void initialize();
    void render();
	
private:
    GLuint loadShader(GLenum type, const char *source);
	
    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;//TODO:aufräumen,entfernen
	GLsizei num_elements_to_draw;
	GLuint CreateSimpleTexture2D();
	void GlSupplyBufferData();
	int shader_positionLoc,shader_projMatrixLoc,shader_texCoordLoc,shader_textureLoc;
	GLuint texture_id;
    QOpenGLShaderProgram *program;
    int m_frame;
};
#endif // GLWIDGET_H
