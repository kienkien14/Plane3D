#include<iostream>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
GLfloat teta = 0; //khai bao toan cuc
GLfloat objectX = 0.0;
GLfloat objectY = 0.0;
GLfloat objectZ = 0.0;
GLfloat rotationAngle = 0.0;
GLfloat rotationSpeed = 1.0;
GLfloat speed = 0.1; // Tốc độ di chuyển của máy bay

using namespace std;

void truc() {
	glDisable(GL_LIGHTING);// tắt chiếu sángA
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0); //red
	glVertex3f(10, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0); //green
	glVertex3f(0.0, 10, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glColor3f(0.0, 0.0, 1.0); //blue
	glVertex3f(0.0, 0.0, 10);
	glVertex3f(0.0, 0.0, 0.0);

	glEnd();
	glEnable(GL_LIGHTING);
}

void canhQuat() {
	//ve canh quat
	glTranslatef(0, 0, -1.2);
	glScaled(0.1, 0.6, 1.2); //mỏng, r 
	glutSolidCone(1, 1, 20, 20);
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //xóa bộ đệm 
	glPopMatrix();	//lay ngan xep ra thuc hien 
	glPushMatrix();//dua mtran bien doi vao ngan xep
	truc();
	glPopMatrix();

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT2);
	glEnable(GL_LIGHT0);// nguồn sáng

	glPushMatrix();
	glTranslatef(objectX, objectY, objectZ);
	glRotatef(rotationAngle, 0, 0, 1); // Xoay theo trục z

    //thân máy bay
	glPushMatrix();
	glScaled(2, 0.5, 0.5);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();
	glDisable(GL_LIGHT0);

	//dau quat
	glEnable(GL_LIGHT1);
	glPushMatrix();
	glTranslatef(-3.8, 0, 0);
	glScaled(0.5, 0.3, 0.3);
	glutSolidSphere(1, 50, 50); //r, tron tru,muon ma
	glPopMatrix();

	//cánh trên phai
	glPushMatrix();
	glTranslatef(-1.5, 1.5, 0);
	glRotated(77, 0, 0, 1); //quanh z 60 độ
	glScaled(1.3, 0.4, 0.25); // co dan
	glutSolidSphere(2, 50, 50);
	glPopMatrix();
	
	//cánh trên trai
	glPushMatrix();
	glTranslatef(-1.5, -1.5, 0);
	glRotated(-77, 0, 0, 1);
	glScaled(1.3, 0.4, 0.25);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();

	//canh duoi phai
	glPushMatrix();
	glTranslatef(3, 1, 0);
	glRotated(77, 0, 0, 1); //quanh z 60 độ
	glScaled(1, 0.5, 0.3); //dai , ngang
	glutSolidSphere(1, 50, 50);
	glPopMatrix();

	//canh duoi trai
	glPushMatrix();
	glTranslatef(3, -1, 0);
	glRotated(-77, 0, 0, 1); //quanh z 60 độ
	glScaled(1, 0.5, 0.3); //dai , ngang
	glutSolidSphere(1, 50, 50);
	glPopMatrix();
	glDisable(GL_LIGHT1);

	//canh quat
	glEnable(GL_LIGHT0);// nguồn sáng
	glPushMatrix();
	glTranslatef(-4, 0, 0); //tt xoay ox
	glRotatef(teta, 1, 0, 0);
	canhQuat();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, 0, 0);
	glRotatef(teta, 1, 0, 0);
	glRotatef(120, 1, 0, 0); //xoay td ox
	canhQuat();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, 0, 0);
	glRotatef(teta, 1, 0, 0);
	glRotatef(240, 1, 0, 0);
	canhQuat();
	glPopMatrix();
	
	//duoi
	glPushMatrix();
	glTranslatef(3.5, 0, 0.6);
	glRotated(-70, 0, 1, 0);
	glScaled(1.2, 0.5, 0.6); //dai , loi 
	glutSolidSphere(1, 50, 50);
	glPopMatrix();

	//chân máy bay sau
	glPushMatrix();
	glTranslatef(1, 0.5, -1);
	glScaled(0.25, 0.25, 1.2); //ngang ,rong,cao
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, -0.5, -1);
	glScaled(0.25, 0.25, 1.2);
	glutSolidCube(1);
	glPopMatrix();

	//chân máy bay trc
	glPushMatrix();
	glTranslatef(-1.5, 1.5, -0.5);
	glScaled(0.25, 0.25, 1.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, -1.5, -0.5);
	glScaled(0.25, 0.25, 1.5);
	glutSolidCube(1);
	glPopMatrix();
	glDisable(GL_LIGHT0);

	//cabin
	glEnable(GL_LIGHT2);
	glPushMatrix();
	glTranslatef(-1.5, 0, 0.8);
	glScaled(1.4, 0.5, 0.8);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();

	// khoang
	glPushMatrix();
	glTranslatef(0.4, 0, 0);
	glScaled(0.3, 1.1, 0.3);
	glutSolidSphere(1, 50, 50); //r, tron tru,muon ma
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8, 0, 0);
	glScaled(0.3, 1.1, 0.3);
	glutSolidSphere(1, 50, 50); //r, tron tru,muon ma
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, 0, 0);
	glScaled(0.3, 1.05, 0.3);
	glutSolidSphere(1, 50, 50); //r, tron tru,muon ma
	glPopMatrix();

	//bánh xe sau
	glPushMatrix();
	glTranslatef(1, 0.5, -1.5);
	glRotatef(teta, 0, 1, 0); //banh quay
	glRotatef(90, 1, 0, 0); // xoay 90 ox
	glutSolidTorus(0.2, 0.4, 50, 50); //r trong, r ngoai,hiệu ứng xoắn ốc,độ mịn
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, -0.5, -1.5);
	glRotatef(teta, 0, 1, 0); //banh quay
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(0.2, 0.4, 50, 50);
	glPopMatrix();

	//bánh xe trc
	glPushMatrix();
	glTranslatef(-1.5, 1.5, -1.2);
	glRotatef(teta, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(0.2, 0.4, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, -1.5, -1.2);
	glRotatef(teta, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(0.2, 0.4, 50, 50);
	glPopMatrix();
	glDisable(GL_LIGHT2);

	glPopMatrix();
	teta = teta + 0.8;
	if (teta >= 360)teta = 0;
	glutPostRedisplay();
	glFlush();
	glutSwapBuffers();//hoán đổi hai bộ đệm hiển thị
}

void KeyboardFunc(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
		objectX -= speed; // Di chuyển lên trên
		break;
	case 's':
		objectX += speed; // Di chuyển xuống dưới
		break;
	case 'a':
		objectY -= speed; // Di chuyển sang trái
		break;
	case 'd':
		objectY += speed; // Di chuyển sang phải
		break;
	case 'z':
		objectZ += speed; // Di chuyển sang trái
		break;
	case 'c':
		objectZ -= speed; // Di chuyển sang phải
		break;
	case 'q':
		rotationAngle += rotationSpeed; // Xoay trái
		break;
	case 'e':
		rotationAngle -= rotationSpeed; // Xoay phải
		break;
	}

	glutPostRedisplay();
}

void init() {
	glClearColor(0.7, 0.9, 1.0, 1.0); //hinh nen
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING); //chế độ chiếu sáng

	glEnable(GL_LIGHT0);// nguồn sáng
	//r,g,b,a la độ trộn trong suốt
	GLfloat posi[] = { 0.0, 0.0, 1.0, 1.0 }; //tọa độ của nguồn sáng (chiếu từ oz)
	GLfloat ambient[] = { 0.5, 0.25, 0.0, 0.5 }; //ánh sáng môi trường (mau ngoai)
	GLfloat diffu[] = { 0.75, 0.5, 0.0, 1.0 };//khuếch tán đối tượng (mau dt)
	GLfloat specu[] = { 1.0, 1.0, 1.0, 1.0 };//ánh sáng trắng
	glLightfv(GL_LIGHT0, GL_POSITION, posi);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffu);

	glEnable(GL_LIGHT1);// nguồn sáng
	GLfloat posiBlue[] = { 0.0, 0.0, 1.0, 1.0 }; //tọa độ của nguồn sáng (chiếu từ oz)
	GLfloat ambientBlue[] = { 0.0, 0.3, 0.3, 1.0 }; //r,g,b,
	GLfloat diffuseBlue[] = { 0.0, 0.3, 0.3, 1.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, posiBlue);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambientBlue); // Màu ánh sáng môi trường xanh dương
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseBlue); // Màu ánh sáng khuếch tán xanh dương

	glEnable(GL_LIGHT2);// nguồn sáng
	GLfloat posiGreen[] = { 0.0, 0.0, 1.0, 1.0 }; //tọa độ của nguồn sáng (chiếu từ oz)
	GLfloat ambientSilver[] = { 0.6, 0.6, 0.6, 1.0 }; // Màu ánh sáng môi trường bạc
	GLfloat diffuseSilver[] = { 0.6, 0.6, 0.6, 1.0 }; // Màu ánh sáng khuếch tán bạc
	glLightfv(GL_LIGHT2, GL_POSITION, posiGreen);
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambientSilver);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseSilver);
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (GLfloat)w / (GLfloat)h, 1, 200);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//camera ,camera nhìn đến và hướng lên trên
	gluLookAt(-20, 20, 20, 0, 0, 0, 0, 0, 1);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); //khởi tạo thư viện
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(1000, 650);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Plane 3D");
	init();
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(KeyboardFunc); // Đăng ký hàm xử lý phím
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}



