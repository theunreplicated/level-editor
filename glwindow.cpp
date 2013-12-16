#include "glwindow.h"
#include <assimp\Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>  
#include <qstring.h>

GLWindow::GLWindow()
    : program(0)
    , m_frame(0)
{

}



/*
GLuint GLWindow::loadShader(GLenum type, const char *source)
{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, 0);
    glCompileShader(shader);
    return shader;
}
*/

/*
void GLWindow::initialize()
{
	static const char *vertexShaderSource =
    "attribute highp vec4 posAttr;\n"
    "attribute lowp vec4 colAttr;\n"
    "varying lowp vec4 col;\n"
    "uniform highp mat4 matrix;\n"
    "void main() {\n"
    "   col = colAttr;\n"
    "   gl_Position = matrix * posAttr;\n"
    "}\n";

static const char *fragmentShaderSource =
    "varying lowp vec4 col;\n"
    "void main() {\n"
    "   gl_FragColor = col;\n"
    "}\n";



    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    m_program->link();
    m_posAttr = m_program->attributeLocation("posAttr");
    m_colAttr = m_program->attributeLocation("colAttr");
    m_matrixUniform = m_program->uniformLocation("matrix");
}

void GLWindow::render()
{
    glViewport(0, 0, width(), height());

    glClear(GL_COLOR_BUFFER_BIT);

    m_program->bind();

    QMatrix4x4 matrix;
    matrix.perspective(60, 4.0/3.0, 0.1, 100.0);
    matrix.translate(0, 0, -2);
    matrix.rotate(100.0f * m_frame / 50, 0, 1, 0);

    m_program->setUniformValue(m_matrixUniform, matrix);

    GLfloat vertices[] = {
        0.0f, 0.707f,
        -0.5f, -0.5f,
        0.5f, -0.5f
    };

    GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };

    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    m_program->release();

    ++m_frame;
	
}*/
/*
GLWidget::GLWidget(QWidget *parent):QGLWidget(parent)
{
    //setAttribute(Qt::WA_PaintOnScreen);
    //setAttribute(Qt::WA_NoSystemBackground);
    //setAutoBufferSwap(false);
	//http://qt-project.org/doc/qt-5.0/qtgui/openglwindow.html
	
}
GLWidget::~GLWidget(){}
void GLWidget::initializeGL()//override
{
   glClearColor(0.0f,1.0f,0.0f,1.0f);//beim drawen qpainter.beginnativedrawing und qpainter.endnativedrawing
   openglINIT();
   GLfloat vVertices[] = { -0.5f,  0.5f, 0.0f,  // Position 0
                            0.0f,  0.0f,        // TexCoord 0 
                           -0.5f, -0.5f, 0.0f,  // Position 1
                            0.0f,  1.0f,        // TexCoord 1
                            0.5f, -0.5f, 0.0f,  // Position 2
                            1.0f,  1.0f,        // TexCoord 2
                            0.5f,  0.5f, 0.0f,  // Position 3
                            1.0f,  0.0f         // TexCoord 3
                         };
   GLushort indices[] = { 0, 1, 2, 0, 2, 3 };
      
   // Set the viewport
   glViewport ( 0, 0, width(), height() );
   
   // Clear the color buffer
   glClear ( GL_COLOR_BUFFER_BIT );
   program.bind();//
   // Use the program object
   //glUseProgram ( userData->programObject );

   // Load the vertex position
   glVertexAttribPointer ( shader_positionLoc, 3, GL_FLOAT, 
                           GL_FALSE, 5 * sizeof(GLfloat), vVertices );
   // Load the texture coordinate
   glVertexAttribPointer ( shader_texCoordLoc, 2, GL_FLOAT,
                           GL_FALSE, 5 * sizeof(GLfloat), &vVertices[3] );

   glEnableVertexAttribArray ( shader_positionLoc );
   glEnableVertexAttribArray ( shader_texCoordLoc);

   // Bind the texture
   glActiveTexture ( GL_TEXTURE0 );
   glBindTexture ( GL_TEXTURE_2D, texture_id );

   // Set the sampler texture unit to 0
   glUniform1i ( shader_textureLoc, 0 );

   glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices );

   //eglSwapBuffers ( esContext->eglDisplay, esContext->eglSurface );
   program.release();





   //asssimp,todo:auslagern
    Assimp::Importer importer;

   const aiScene* scene = importer.ReadFile("SimpleCube.md5mesh", 
        aiProcess_CalcTangentSpace       | 
        aiProcess_Triangulate            |
        aiProcess_JoinIdenticalVertices  |
        aiProcess_SortByPType);
  
  // If the import failed, report it
  if( !scene)
  {
   qDebug( importer.GetErrorString());
    
  }else{//TODO:vllt.ändern,da es z.t nur Fehler geben kann wie Texture-IMport-Fehler,man kann das Model jedoch trotzdem nutzen,gucken wie das genau gehandelt wird,hinweis:ok so,das behandelt anscheinen dnur import.fehler
  //import OK
  
	  glEnable(GL_DEPTH_TEST);
	  if(scene->HasMeshes()){
		  qDebug("meshes");
		  qDebug(QString::number(scene->mNumMeshes).toStdString().c_str());
		  
		//mesh handle
		 //TODO:assert falls mNumMeshes= (sizeof(scene->mMeshes)/sizeof(*scene->mMeshes)
		  for(int i=0;i<scene->mNumMeshes;i++){
			  aiMesh*mesh=scene->mMeshes[i];
				//vertices 
				*/
			  /*
			 GLfloat *render_vertices;
			 render_vertices= new GLfloat[mesh->mNumVertices*3];
				unsigned int vertices_write_Pos=0;//Private
			  for(int vi=0;vi<mesh->mNumVertices;vi++){
				  //qDebug("numvertices");
				  //qDebug(QString::number(mesh->mNumVertices).toStdString().c_str());
				  //insert order0>x,y,z
				  render_vertices[vertices_write_Pos+0]=mesh->mVertices[vi].x;
				  render_vertices[vertices_write_Pos+1]=mesh->mVertices[vi].y;
				  render_vertices[vertices_write_Pos+2]=mesh->mVertices[vi].z;

				vertices_write_Pos+=3;  

			  //qDebug(QString::number(render_vertices[70]).toStdString().c_str());
			  
			  }*/
/*
			  if(mesh->HasPositions()){
			  //vertex
			  
			  }
			  if(mesh->HasNormals()){
			  //normals
			  
			  }
		



			 		      }
		  	  }


	  if(scene->HasMaterials()){
		 qDebug("materials");
		 qDebug(QString::number(scene->mNumMaterials).toStdString().c_str());
	    for(int i=0;i<scene->mNumMaterials;i++){
			aiMaterial*material=scene->mMaterials[i];
			//qDebug(QString::number(material->mNumProperties).toStdString().c_str());

		}
	  }
	  if(scene->HasTextures()){
	  
	  qDebug("textures");
		qDebug(QString::number(scene->mNumTextures).toStdString().c_str());
	    
	  }
	  if(scene->HasLights()){
		qDebug("lights");
		qDebug(QString::number(scene->mNumLights).toStdString().c_str());
	  }




	  if(scene->HasCameras()){
		qDebug("cameras");
		  qDebug(QString::number(scene->mNumCameras).toStdString().c_str());
	  
	  }
	  if(scene->HasAnimations()){
		qDebug("animations");
		qDebug(QString::number(scene->mNumAnimations).toStdString().c_str());
	  }
	  

  
  }



}

GLuint GLWindow::CreateSimpleTexture2D( )
{
   // Texture object handle
   GLuint textureId;
   
   // 2x2 Image, 3 bytes per pixel (R, G, B)
   GLubyte pixels[4 * 3] =
   {  
      255,   0,   0, // Red
        0, 255,   0, // Green
        0,   0, 255, // Blue
      255, 255,   0  // Yellow
   };

   // Use tightly packed data
   glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );

   // Generate a texture object
   glGenTextures ( 1, &textureId );

   // Bind the texture object
   glBindTexture ( GL_TEXTURE_2D, textureId );

   // Load the texture
   glTexImage2D ( GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels );

   // Set the filtering mode
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

   return textureId;

}
*/
void GLWindow::initialize(){
//vertex shader erstellen
	glEnable(GL_DEPTH_TEST);
QGLShader *vertex_shader = new QGLShader(QGLShader::Vertex, this);//https://qt.gitorious.org/qt/qt/source/8f84a6e549b90286afb2e4af378ea8b271babcd5:examples/opengl/hellogl_es2/glwidget.cpp
const char* vertex_shader_src=//https://code.google.com/p/opengles-book-samples/source/browse/trunk/Windows/Chapter_9/Simple_Texture2D/Simple_Texture2D.c
	  "attribute vec4 a_position;   \n"
	  "uniform mat4 projMatrix; \n"
      //"attribute vec2 a_texCoord;   \n"
      //"varying vec2 v_texCoord;     \n"
      "void main()                  \n"
      "{                            \n"

      "   gl_Position = a_position*projMatrix; \n"
     // "   v_texCoord = a_texCoord;  \n"
      "}                            \n";


//frag shader
QGLShader *fragment_shader = new QGLShader(QGLShader::Fragment, this);//geometry-shader gibts in gles 2.0 net
const char*fragment_shader_src= "precision mediump float;                            \n"
    //  "varying vec2 v_texCoord;                            \n"
      //"uniform sampler2D s_texture;                        \n"
      "void main()                                         \n"
      "{                                                   \n"
	  "  gl_FragColor =vec4(1.0,1.0,1.0,1.0);\n"
      "}                                                   \n";

program = new QOpenGLShaderProgram(this);
   program->addShaderFromSourceCode(QOpenGLShader::Vertex,vertex_shader_src);
    program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragment_shader_src);
    program->link();


shader_positionLoc=program->attributeLocation("a_position");
shader_projMatrixLoc=program->uniformLocation("projMatrix");
//shader_texCoordLoc=program->attributeLocation("a_texCoord");
//shader_textureLoc=program->uniformLocation("s_texture");
//texture_id=CreateSimpleTexture2D();


//	aiVector3D pc[]={aiVector3D(-1.0f,-1.0f,0.0f),aiVector3D(1.0f,-1.0f,0.0f),aiVector3D(-1.0f,1.0f,0.0f)};

GlSupplyBufferData();

}

void GLWindow::GlSupplyBufferData(){

	   Assimp::Importer importer;

   const aiScene* scene = importer.ReadFile("cube.3DS", 
        aiProcess_CalcTangentSpace       | 
        aiProcess_Triangulate            |
        aiProcess_JoinIdenticalVertices  |
        aiProcess_SortByPType);
  GLuint buffer;
  // If the import failed, report it
  if( !scene)
  {
   qDebug( importer.GetErrorString());return;
    
  }else{
	  //ok handle
	  //render_node(scene->mRootNode,scene);
	  aiMesh * mesh=scene->mMeshes[0]; /*
	  std::map<float,unsigned int, std::greater<float> > smap;

	  for (unsigned int iFace = 0; iFace < mesh->mNumFaces;++iFace)
        {
                const aiFace* pcFace = &mesh->mFaces[iFace];
                float fDist = 0.0f;
                for (unsigned int c = 0; c < 3;++c)
                {
                        aiVector3D vPos = mesh->mVertices[pcFace->mIndices[c]];
                        
                        fDist += vPos.SquareLength();
                }
                smap.insert(std::pair<float, unsigned int>(fDist,iFace));
        }

	  unsigned int * aiIndices;
	  
	  for (std::map<float,unsigned int, std::greater<float> >::const_iterator
                        i =  smap.begin();
                        i != smap.end();++i)
						 {
                        const aiFace* pcFace =  &mesh->mFaces[(*i).second];
                        *aiIndices++ = (unsigned int)pcFace->mIndices[0];
                        *aiIndices++ = (unsigned int)pcFace->mIndices[1];
                        *aiIndices++ = (unsigned int)pcFace->mIndices[2];
                }*/

	/*  unsigned int *faceArray;
	faceArray = (unsigned int *)malloc(sizeof(unsigned int) * mesh->mNumFaces * 3);
		unsigned int faceIndex = 0;

		for (unsigned int t = 0; t < mesh->mNumFaces; ++t) {
			const aiFace* face = &mesh->mFaces[t];

			memcpy(&faceArray[faceIndex], face->mIndices,3 * sizeof(unsigned int));
			faceIndex += 3;
		}
		*/
	  unsigned short * aiIndices= new unsigned short[mesh->mNumFaces*3];
	  int vcount=-1;
for (int j=0; j<mesh->mNumFaces; j++)
{
                        const struct aiFace  face = mesh->mFaces[j];
//zuerst mal auf dem Stack um keine Memory Leaks zu erzeugen(bin mir aber nicht ganz sicher ob welche entstehen,da s n error bei delete gibt)
						aiIndices[vcount+1]=face.mIndices[0];qDebug()<<"--"<<face.mIndices[0];
	aiIndices[vcount+2]=face.mIndices[1];qDebug()<<face.mIndices[1];
	aiIndices[vcount+3]=face.mIndices[2];qDebug()<<face.mIndices[2];
	vcount+=3;				   
            }


float *aiVertices= new float[mesh->mNumVertices*3];
//aiVertices[0]=1;
//*aiVertices++=2;
//*aiVertices--;

//*aiVertices++=2;
int facecount=-1;
for (int i=0;i<mesh->mNumVertices;i++){
	
	aiVertices[facecount+1]=mesh->mVertices[i].x;
	aiVertices[facecount+2]=mesh->mVertices[i].y;
	aiVertices[facecount+3]=mesh->mVertices[i].z;
	facecount+=3;

}qDebug()<<facecount<<mesh->mNumVertices;
//qDebug()<<mesh->mVertices[mesh->mNumVertices-1].x<<"vertices";
qDebug()<<aiIndices[0]<<"indices";

                //num_indices.push_back(indices.size());


	/*GLfloat vertices[] = { -0.5f,  0.5f, 0.0f,  // Position 0          
                           -0.5f, -0.5f, 0.0f,  // Position 1
                            0.5f, -0.5f, 0.0f,  // Position 2
                            0.5f,  0.5f, 0.0f,  // Position 3
                         };
	GLushort indices[]={0, 1, 2, 0, 2, 3};*/
		float vertices[]={1, -1, 0, 
    1, 1, 0,
    -1, 1, 0,
    -1, -1, 0,
    // Back
   1, 1, -2,
    -1, -1, -2,
    1, -1, -2,
    -1, 1, -2,
    // Left
    -1, -1, 0, 
    -1, 1, 0,
    -1, 1, -2,
    -1, -1, -2,
    // Right
   1, -1, -2,
   1, 1, -2,
    1, 1, 0,
   1, -1, 0,
    // Top
    1, 1, 0,
    1, 1, -2,
    -1, 1, -2,
    -1, 1, 0,
    // Bottom
   1, -1, -2,
    1, -1, 0,
    -1, -1, 0, 
    -1, -1, -2};

		unsigned short indices[] = {
    // Front
    0, 1, 2,
    2, 3, 0,
    // Back
    4, 5, 6,
    4, 5, 7,
    // Left
    8, 9, 10,
    10, 11, 8,
    // Right
    12, 13, 14,
    14, 15, 12,
    // Top
    16, 17, 18,
    18, 19, 16,
    // Bottom
    20, 21, 22,
    22, 23, 20
};
//ganz wichtig:unsigned int funz net,unsigned short muss es sein
/*		unsigned short zindices[]={0, 
1, 
2, 
0, 
2, 
3};

		float zvertices[]={-49.2396, 
75.9832, 
0, 
-49.2397, 
-74.0167, 
0, 
49.5162, 
-74.0168, 
0, 
49.5162, 
75.9832, 
0 };*/
GLuint buffer;
 glGenBuffers(1, &buffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);

  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short) * mesh->mNumFaces * 3, aiIndices, GL_STATIC_DRAW);

        // buffer for*/
 /*glGenBuffers(1, &buffer);
            glBindBuffer(GL_ARRAY_BUFFER, buffer);//sizeof vertices/sizeof float//TODO:float durch glfloat geändert,müsste gehen ,beobachten
           glBufferData(GL_ARRAY_BUFFER, sizeof(float)*3*(sizeof(zvertices)/sizeof(float)), zvertices, GL_STATIC_DRAW);
            glEnableVertexAttribArray(shader_positionLoc);
            glVertexAttribPointer(shader_positionLoc, 3, GL_FLOAT, 0, 0, 0);
	*/


	glGenBuffers(1, &buffer);
          glBindBuffer(GL_ARRAY_BUFFER, buffer);
		  glBufferData(GL_ARRAY_BUFFER, sizeof(float)*3*mesh->mNumVertices,aiVertices, GL_STATIC_DRAW);
            glEnableVertexAttribArray(shader_positionLoc);
            glVertexAttribPointer(shader_positionLoc, 3, GL_FLOAT, 0, 0, 0);
			//qDebug()<<sizeof(float)*3*mesh->mNumVertices;
			
			qDebug()<<sizeof(aiVertices);
			
			GLenum err;while ((err = glGetError()) != GL_NO_ERROR) {
        qDebug() << "OpenGL error: " << err << endl;
    }



//glGenBuffers(1, &buffer);
//lBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);//*sizeof vertices/sizeof float*/
//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short)*(sizeof(zindices)/sizeof(unsigned short)), zindices, GL_STATIC_DRAW);


			//num_elements_to_draw=(sizeof(indices)/sizeof(GLshort));
			num_elements_to_draw=mesh->mNumFaces*3;
			//num_elements_to_draw=36;
//num_elements_to_draw=6;
  }



}
void render_node(aiNode * node,const aiScene*scene){
	qDebug(node->mName.C_Str());



};


void GLWindow::render(){//TODO:calls changen,das hier wird 2x aufgerufen(sollte nicht sein,nur 1x)




	glClearColor(0.0f,0.0f,0.0f,1.0f);//beim drawen qpainter.beginnativedrawing und qpainter.endnativedrawing


	  program->bind();


	   QMatrix4x4 matrix;
    //matrix.perspective(60, 4.0/3.0, 0.1, 100.0);
   //matrix.translate(0.0001, 0, 0);
    //matrix.rotate(100.0f * 360 / 50, 0, 1, 0);
	   matrix.rotate(100,50,1,0);

	  //matrix.scale(0.5f);//für eigene vertices,indices
	matrix.scale(0.01f);
	
	program->setUniformValue(shader_projMatrixLoc,matrix);
 



	



	//scene->mMeshes[0]->mVertices
		//glVertexAttribPointer(shader_positionLoc,3, GL_FLOAT, GL_FALSE, 0,vertices);
    //glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

    //glEnableVertexAttribArray(0);
    //glEnableVertexAttribArray(1);
	
	
	//GLenum primitive_mode;
	//TODO:Check if has meshes
	/*switch(scene->mMeshes[0]->mFaces->mNumIndices){
	case 1:primitive_mode=GL_POINTS;break;
	case 2:primitive_mode=GL_LINES;break;
	case 3:primitive_mode=GL_TRIANGLES;break;
	default:qDebug("primitive_ polygon");break;
	}*///TODO:glpolygon alternative finden
	
	//glDrawArrays(primitive_mode, 0, 3);

	 glDrawElements(GL_TRIANGLES,num_elements_to_draw,GL_UNSIGNED_SHORT,(void*)0);
    //glDisableVertexAttribArray(1);
    //glDisableVertexAttribArray(0);

    
	program->release();







	qDebug("call");

}








/*
*/
//http://www.lighthouse3d.com/cg-topics/code-samples/importing-3d-models-with-assimp/