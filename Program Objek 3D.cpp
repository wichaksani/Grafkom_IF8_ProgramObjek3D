/*
 Kelompok:
          10108384 - Winda Tania
          10108387 - Hidayatuaulia Wiris Wichaksani
          10108391 - Verra Verdianti
          10108399 - Yuni Retna Ningsih
          10108421 - Marcelina Girsang
 Kelas : IF - 8
*/
 
#include <gl/glut.h> 
   
char title[] = "Program Objek 3D";
int windowWidth  = 640;   
int windowHeight = 480;    
int windowPosX   = 50;     
int windowPosY   = 50;    
bool fullScreenMode = true;
 
GLfloat angleTrapesium = 0.0f;
   
void initGL(GLvoid) {
   glShadeModel(GL_SMOOTH);  
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  
   glClearDepth(1.0f);      
   glEnable(GL_DEPTH_TEST);   
   glDepthFunc(GL_LEQUAL);   
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
}
   
void display(void) {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   
   glLoadIdentity();                   
   glTranslatef(1.5f, 0.0f, -6.0f);    
   glRotatef(angleTrapesium, 1.0f, 1.0f, 1.0f);	
      
   glBegin(GL_QUADS);                 
      glColor3f(0.0f, 1.0f, 0.0f);    // hijau bagian atas trapesium
      glVertex3f( 1.0f, 1.0f, -1.0f); // atas kanan
      glVertex3f(-1.0f, 1.0f, -1.0f); // atas kiri
      glVertex3f(-1.0f, 1.0f,  1.0f); // bawah kiri
      glVertex3f( 1.0f, 1.0f,  1.0f); // bawah kanan
   
      glColor3f(1.0f, 0.5f, 0.0f);     // orange bagian bawah trapesium
      glVertex3f( 2.0f, -2.0f,  2.0f); // atas kanan
      glVertex3f(-2.0f, -2.0f,  2.0f); // atas kiri
      glVertex3f(-2.0f, -2.0f, -2.0f); // bawah kiri
      glVertex3f( 2.0f, -2.0f, -2.0f); // bawah kanan
   
      glColor3f(1.0f, 0.0f, 0.0f);     // merah bagian depan trapesium
      glVertex3f( 1.0f,  1.0f, 1.0f);  // atas kanan
      glVertex3f(-1.0f,  1.0f, 1.0f);  // atas kiri
      glVertex3f(-2.0f, -2.0f, 2.0f);  // bawah kiri
      glVertex3f( 2.0f, -2.0f, 2.0f);  // bawah kanan
   
      glColor3f(1.0f, 1.0f, 0.0f);     // kuning bagian belakang trapesium
      glVertex3f( 2.0f, -2.0f, -2.0f); // bawah kiri
      glVertex3f(-2.0f, -2.0f, -2.0f); // bawah kanan
      glVertex3f(-1.0f,  1.0f, -1.0f); // atas kanan
      glVertex3f( 1.0f,  1.0f, -1.0f); // atas kiri
   
      glColor3f(0.0f, 0.0f, 1.0f);     // biru bagian kiri trapesium
      glVertex3f(-1.0f,  1.0f,  1.0f); // atas kanan
      glVertex3f(-1.0f,  1.0f, -1.0f); // atas kiri
      glVertex3f(-2.0f, -2.0f, -2.0f); // bawah kiri
      glVertex3f(-2.0f, -2.0f,  2.0f); // bawah kanan
   
      glColor3f(1.0f, 0.0f, 1.0f);     // ungu bagian kanan trapesium
      glVertex3f( 1.0f,  1.0f, -1.0f); // atas kanan
      glVertex3f( 1.0f,  1.0f,  1.0f); // atas kiri
      glVertex3f( 2.0f, -2.0f,  2.0f); // bawah kiri
      glVertex3f( 2.0f, -2.0f, -2.0f); // bawah kanan
   glEnd();
   
   glutSwapBuffers(); 
   
   angleTrapesium -= 0.15f; 
}
   
void reshape(GLsizei width, GLsizei height) { 
   if (height == 0) height = 1; 
   
   glViewport(0, 0, width, height);
   
   glMatrixMode(GL_PROJECTION); 
   glLoadIdentity();           
   gluPerspective(45.0, (float)width / (float)height, 0.1, 100.0);
    
   glMatrixMode(GL_MODELVIEW); 
   glLoadIdentity();          
}
   

void keyboard(unsigned char key, int x, int y) {
   switch (key) {
      case 27:      
         exit(0); break;
      default:
         break;
   }
}
   

void specialKey(int key, int x, int y) {
   switch (key) {
      case GLUT_KEY_F1:   
         fullScreenMode = !fullScreenMode;        
         if (fullScreenMode) {                     
            windowPosX   = glutGet(GLUT_WINDOW_X); 
            windowPosY   = glutGet(GLUT_WINDOW_Y);
            windowWidth  = glutGet(GLUT_WINDOW_WIDTH);
            windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
            glutFullScreen();                     
         } else {                                       
            glutReshapeWindow(windowWidth, windowHeight); 
            glutPositionWindow(windowPosX, windowPosX);   
         }
         break;
      default:
         break;
   }
}
   

int main(int argc, char** argv) {
   glutInit(&argc, argv);    
   glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); 
   glutInitWindowSize(windowWidth, windowHeight);  
   glutInitWindowPosition(windowPosX, windowPosY); 
   glutCreateWindow(title);    
   glutFullScreen();           
   glutDisplayFunc(display);  
   glutReshapeFunc(reshape);   
   glutKeyboardFunc(keyboard);  
   glutSpecialFunc(specialKey);
   glutIdleFunc(display);      
   initGL();        
   glutMainLoop();    
   return 0;
}
