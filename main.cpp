#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include<GL/gl.h>
#include <stdbool.h>


using namespace std;

float missileY1 = 11.2f;
float missileY2 = 0.0f;
float offset = 2.0f;
bool truckHit = false;
bool missileFalling = false;
float missileY = 13.5f;
float _move10 = 0.0f;
float _move9 = 0.0f;
float _angle2 = 0.0f;
float _move8 = -19.0f;
float _angle1 = 0.0f;
float  _move5 = 0.0f;
float _move4 = 0.0f;
float _move2 =0.0f;
float _move3 =0.0f;
float _move7 =0.0f;
float _move12 = -1.0f;
float position7 = 0.0f;
float _move = 0.0f;
float _move11 = 0.0f;
float _move13 = 0.0f;
bool isFalling = false;
float tankX = 0.45f, tankY = 2.02f, tankWidth = 2.65f, tankHeight = 0.79f; // Tank position and dimensions
float missileWidth = 0.48f, missileHeight = 0.0553f; // Missile dimensions
bool isTankMoving = false;
bool isTankMoveAllowed = true;
float missileOffset = 0.2f;
bool missileFalling2 = true;
bool missile_hits_boat();
bool boatHit = false;






void Tank() {
glBegin(GL_POLYGON);
glColor3ub(65,83,59);
glVertex2f(0.7f, 2.47f);
glVertex2f(0.59f, 2.02f);
glVertex2f(3.31f, 2.02f);
glVertex2f(3.40f, 2.24f);
glVertex2f(2.55f, 2.49f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(65,83,59);
glVertex2f(0.45f, 2.81f);
glVertex2f(0.46f, 2.60f);
glVertex2f(1.22f, 2.53f);
glVertex2f(2.26f, 2.49f);
glVertex2f(2.43f, 2.57f);
glVertex2f(4.10f, 2.56f);
glVertex2f(4.09f, 2.67f);
glVertex2f(2.41f, 2.68f);
glVertex2f(2.18f, 2.79f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(28,34,46);
glVertex2f(0.674f, 2.022f);
glVertex2f(1.04f, 1.73f);
glVertex2f(3.00f, 1.73f);
glVertex2f(3.31f, 2.02f);
glEnd();

        glBegin(GL_POLYGON);
    glColor3ub(100,100,100);
   glVertex2f (3.6973607862371, 2.676415335864);
    glVertex2f(4.101598645783, 2.6724524090295);
    glVertex2f(4.1044354231385, 2.5589813148154);
    glVertex2f(3.69,2.56);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(167,33,29);
   glVertex2f (4.1, 2.8);
   glVertex2f (4.4757249416327, 2.617616454387);
    glVertex2f(4.105029722619, 2.4634659672788);
    glEnd();
}


void drawTank() {
glPushMatrix();
glTranslatef(_move, 0.0f, 0.0f);
Tank();
glPopMatrix();
}



void update(int value) {

    _move13 -= 0.01;
    if (_move13 < -45.05) {
        _move13 = +1.0;
    }
_move11 -= 0.001;
if(_move11 <-45.05)
{
_move11= +1.0;
}
    _move12 -= 0.01;
    if (_move12 < -45.05) {
        _move12 = +1.0;
    }

_move2 -= 0.02;
if(_move2 <-45.05)
{
_move2= +1.0;
}

if (_angle1 > 360.0)
{
_angle1 -= 360;
}
_move7 += 0.02;
if (_move7 > 45.05) {
_move7 = -0.5f;
}

glutPostRedisplay();
glutTimerFunc(20, update, 0); // Update every 20 milliseconds
}

void update2(int value) {
_move8 += 0.01;
if (_move8 > 43.05) {
_move8 = -1.0f;
}

_angle2 += 30.00f;
if (_angle2 > 360.0)
{
_angle2 -= 360;
}

glutPostRedisplay();
glutTimerFunc(10, update2, 0);
}

void update4(int value) {
    if (missileFalling) {
        missileY -= 0.1; // Adjust this value for the speed of falling
        if (missileY <= 0.53) { // Check for collision with the truck
            // Stop the missile
            missileFalling = false;
            truckHit = true; // Set truckHit flag to true
        }
    }

    _move4 -= 0.04;
   /* if (_move4 < -45.05) {
        _move4 = +1.0;
    }*/

    if (!truckHit) { // Only update _move5 if truck is not hit
        _move5 -= 0.04;
        if (_move5 < -43.05) {
            _move5 = +1.0;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(20, update4, 0); // Update every 20 milliseconds
}

void update3(int value){
   if (isTankMoveAllowed) { // Check if tank movement is allowed
        _move += 0.01f;
        if (_move > 43.05) {
            _move = -1.0f;
        }
    }
_move9 += 0.01;
if (_move9 > 43.05) {
_move9 = -1.0f;
}

glutPostRedisplay();
glutTimerFunc(10, update3, 0); // Update every 20 milliseconds

}
void update6(int value){

    _move3 += 0.02;
if (_move3 > 43.05) {
_move3 = -1.0f;
}

_move10 += 0.02;
/*if (_move10 > 43.05) {
_move10 = -1.0f;
}*/
glutPostRedisplay();
glutTimerFunc(10, update6 , 0); // Update every 20 milliseconds

}



void tank2()
{
    glBegin(GL_POLYGON);
    glColor3ub(65,83,59);
    glVertex2f(41.0746714694122, 1.8823551007501);
      glVertex2f(40.9349009263592, 2.168544280609);
      glVertex2f(41.5594671559017, 2.4344085732517);
      glVertex2f(43.7978669812626, 2.4346908182521);
      glVertex2f(43.9316194026689, 1.8669048221103);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(28,34,46);
      glVertex2f(41.266536,1.88131750);
      glVertex2f(41.5021457966174, 1.591470314459);
      glVertex2f(43.4654994666242, 1.5844078911858);
     glVertex2f (43.682543,1.86825181);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(65,83,59);
      glVertex2f (39.9361006857423, 2.7094499252191);
       glVertex2f(41.770125718901, 2.7037718291414);
       glVertex2f(41.975132735678, 2.8288133195257);
       glVertex2f(43.8963072863019, 2.8203319639802);
       glVertex2f(43.9174945561221, 2.5802095726945);
      glVertex2f (43.175489,2.43461);
      glVertex2f (41.96515,2.4344597);
       glVertex2f(41.7697715871482, 2.5292620127874);
       glVertex2f(39.9381148335589, 2.5408189641504);
    glEnd();

       glBegin(GL_POLYGON);
        glColor3ub(100,100,100);
    glVertex2f (39.8509292445739, 2.7066108771803);
      glVertex2f (40.59925,2.707396);
      glVertex2f (40.60194,2.5366);
      glVertex2f (39.8565901743251, 2.5375437381389);
       glEnd();

           glBegin(GL_POLYGON);
        glColor3ub(167,33,29);
      glVertex2f(39.3302065067401, 2.5991012803165);
      glVertex2f(39.8515186935722, 2.8405143064233);
      glVertex2f(39.8585161725901, 2.3821794307713);
       glEnd();
}

void drawtank2(){
glPushMatrix();
glTranslatef(_move11, 0.0f, 0.0f);
tank2();
glPopMatrix();
}

void road(){
glColor3ub(196,196,196);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(45.05, -0.108);
glVertex2f(45.04, 2.94);
glVertex2f(0, 2.99);
glEnd();
}

void Road2(){
glColor3ub(255,255,255);
glBegin(GL_LINE_LOOP);
glVertex2f(0,1.41);
glVertex2f(45.05,1.41);
glEnd();
}

void water(){
glColor3ub(68,221,255);
glBegin(GL_POLYGON);
glVertex2f(0, 2.99);
glColor3ub(35,137,218);
glVertex2f(0, 6.10);
glVertex2f(45.03,6.13);
glColor3ub(35,137,218);
glVertex2f(45.04, 2.94);
glEnd();

}

void bridge(){
glColor3ub(175,89,62);
glBegin(GL_POLYGON);
glVertex2f(32.24,6.69);
glVertex2f(32.24,12.41);
glVertex2f(34.72,12.43);
glVertex2f(34.66,6.77);
glVertex2f(34.79,6.78);
glVertex2f(34.79,6.56);
glVertex2f(34.85,3.62);
glVertex2f(31.99,3.62);
glVertex2f(32.05,6.67);
glEnd();
}

void bridge2(){
glColor3ub(175,89,62);
glBegin(GL_POLYGON);
glVertex2f(40.67,6.60);
glVertex2f(40.66,13.12);
glVertex2f(44.02,13.16);
glVertex2f(43.99,6.62);
glVertex2f(43.94,6.62);
glVertex2f(43.94,3.73);
glVertex2f(40.56,3.68);
glVertex2f(40.53,6.59);
glEnd();
}

void road3(){
glColor3ub(175,89,62);
glBegin(GL_POLYGON);
glVertex2f(28.03,6.59);
glVertex2f(32.03,7.16);
glVertex2f(45.03,7.17);
glVertex2f(45.03,6.65);
glVertex2f(31.67,6.57);
glVertex2f(28.03,6.23);
glEnd();
}

void bac(){
glColor3ub(135,206,235);
glBegin(GL_POLYGON);
glVertex2f(0,6.10);
glColor3ub(77 ,78, 78);
glVertex2f(0,20);
glColor3ub(24,181,204);
glVertex2f(45,20);
glColor3ub(135,135,135);
glVertex2f(45.03,6.13);
glEnd();
}

void grass(){
glColor3ub(126,200,80);
glBegin(GL_POLYGON);
glVertex2f(0,6.10);
glVertex2d(0,6.33);
glVertex2f(45.03,6.61);
glVertex2f(45.03,6.13);
glEnd();
}

void line(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(29.45,6.79);
glVertex2d(32.24,11.97);
glEnd();
}

void line2(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(29.55,6.80);
glVertex2d(32.24,11.65);
glEnd();
}
void line3(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(29.72,6.83);
glVertex2d(32.24,11.29);
glEnd();
}
void line4(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(35.71,7.16);
glVertex2d(32.24,12.12);
glEnd();
}
void line5(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(32.24,12.06);
glVertex2d(35.61,7.16);
glEnd();
}
void line6(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(34.70,10.68);
glVertex2d(37.08,7.16);
glEnd();
}
void line7(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(34.70,10.97);
glVertex2d(37.11,7.16);
glEnd();
}
void line8(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(34.71,11.27);
glVertex2d(37.16,7.16);
glEnd();
}
void line9(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(37.32,7.16);
glVertex2d(40.67,12.24);
glEnd();
}
void line10(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(40.67,11.75);
glVertex2d(37.48,7.16);
glEnd();
}
void line11(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(37.67,7.16);
glVertex2d(40.67,11.48);
glEnd();
}
void line12(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(40.66,13.12);
glVertex2d(45.03,7.41);
glEnd();
}
void line13(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(45.03,7.34);
glVertex2d(45.03,7.41);
glEnd();
}
void line14(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(45.03,7.34);
glVertex2d(40.66,12.87);
glEnd();
}
void line15(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(45.03,7.28);
glVertex2d(40.66,12.67);
glEnd();
}
void line16(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(45.02,11.56);
glVertex2d(44.02,12.49);
glEnd();
}
void line17(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(44.02,12.13);
glVertex2d(45.02,11.23);
glEnd();
}
void line18(){
glColor3ub(55,55,55);
glBegin(GL_LINES);
glVertex2f(44.02,11.85);
glVertex2d(45.02,10.76);
glEnd();
}

void building(){
glColor3ub(135,206,235);
glBegin(GL_POLYGON);
glVertex2f(0.42,6.11);
glVertex2d(0.41,7.15);
glVertex2d(1.76,7.15);
glVertex2d(1.76,6.11);
glEnd();
}
void window(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(0.5,7);
glVertex2d(0.83,7);
glVertex2d(0.83,6.82);
glVertex2d(0.5,6.82);
glEnd();
}
void window2(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(1.2,6.99);
glVertex2d(1.5,7);
glVertex2d(1.5,6.84);
glVertex2d(1.2,6.84);
glEnd();
}
void window3(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(0.52,6.5);
glVertex2d(0.82,6.5);
glVertex2d(0.82,6.39);
glVertex2d(0.52,6.39);
glEnd();
}
void window4(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(1.22,6.5);
glVertex2d(1.49,6.5);
glVertex2d(1.49,6.38);
glVertex2d(1.22,6.38);
glEnd();
}

void building2(){
glColor3ub(178,190,181);
glBegin(GL_POLYGON);
glVertex2f(0.7,7.15);
glVertex2d(0.7,8.72);
glVertex2d(1.33,8.68);
glVertex2d(1.33,7.15);
glEnd();
}
void building3(){
glColor3ub(47,86,233);
glBegin(GL_POLYGON);
glVertex2f(1.33,6.11);
glVertex2d(1.34,8.43);
glVertex2d(2.35,8.43);
glVertex2d(2.29,6.11);
glEnd();
}
void building4(){
glColor3ub(255,173,47);
glBegin(GL_POLYGON);
glVertex2f(2.14,6.11);
glVertex2d(2.15,8.62);
glVertex2d(2.58,8.57);
glVertex2d(2.59,6.11);
glEnd();
}

void building5(){
glColor3ub(177,156,217);
glBegin(GL_POLYGON);
glVertex2f(2.58,6.11);
glVertex2d(2.58,7);
glVertex2d(3.61,6.99);
glVertex2d(3.60,6.11);
glEnd();
}
void win(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(2.76,6.83);
glVertex2d(3.08,6.83);
glVertex2d(3.08,6.66);
glVertex2d(2.77,6.66);
glEnd();
}

void win2(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(3.22,6.83);
glVertex2d(3.48,6.83);
glVertex2d(3.48,6.67);
glVertex2d(3.22,6.67);
glEnd();
}
void win3(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(3.23,6.55);
glVertex2d(3.47,6.55);
glVertex2d(3.47,6.37);
glVertex2d(3.24,6.37);
glEnd();
}

void win4(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(2.75,6.53);
glVertex2d(3.07,6.53);
glVertex2d(3.07,6.36);
glVertex2d(2.75,6.36);
glEnd();
}

void building6(){
glColor3ub(178,190,181);
glBegin(GL_POLYGON);
glVertex2f(2.76,7);
glVertex2d(2.76,9);
glVertex2d(3.21,9);
glVertex2d(3.19,6.99);
glEnd();
}
void wi1(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(2.86,8.79);
glVertex2d(2.97,8.79);
glVertex2d(2.97,8.54);
glVertex2d(2.86,8.54);
glEnd();
}
void wi2(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(3.04,8.78);
glVertex2d(3.15,8.78);
glVertex2d(3.14,8.54);
glVertex2d(3.04,8.54);
glEnd();
}
void wi3(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(2.83,7.68);
glVertex2d(2.98,7.68);
glVertex2d(2.98,7.13);
glVertex2d(2.83,7.13);
glEnd();
}
void wi4(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(3.05,7.67);
glVertex2d(3.16,7.67);
glVertex2d(3.16,7.13);
glVertex2d(3.05,7.13);
glEnd();
}
void boat(){
glColor3ub(55,55,55);
glBegin(GL_POLYGON);
glVertex2f(39.56,4.64);
glVertex2d(40.95,4.65);
glVertex2d(41.03,4.54);
glVertex2d(43.40,4.54);
glVertex2f(43.51,4.43);
glVertex2d(44.62,4.44);
glVertex2d(44.49,3.94);
glVertex2d(40.25,3.91);
glEnd();
}

void boatbody(){
glBegin(GL_POLYGON);
glColor3ub(73,47,47);
glBegin(GL_POLYGON);
glVertex2f(41.03,4.54);
glVertex2f(41.25,5.05);
glVertex2f(41.91,5.05);
glVertex2f(42.01,4.87);
glVertex2f(43.22,4.86);
glVertex2f(43.30,4.54);
glEnd();
}
void boatbody2(){
glColor3ub(178,190,181);
glBegin(GL_POLYGON);
glVertex2f(40.39,4.65);
glVertex2f(40.44,4.91);
glVertex2f(40.76,4.90);
glVertex2f(40.84,4.65);
glEnd();
}

void boatbody3(){
glColor3ub(178,190,181);
glBegin(GL_POLYGON);
glVertex2f(42.45,4.87);
glVertex2d(42.54,5.16);
glVertex2d(42.90,5.17);
glVertex2f(42.95,4.86);
glEnd();
}
void boatbody4(){
glColor3ub(178,190,181);
glBegin(GL_POLYGON);
glVertex2f(42.93,4.99);
glVertex2f(43.21,5.21);
glVertex2d(43.23,5.12);
glVertex2d(42.95,4.91);
glEnd();
}

void boatbody5(){
glColor3ub(178,190,181);
glBegin(GL_POLYGON);
glVertex2f(40.39,4.77);
glVertex2f(40.06,4.86);
glVertex2d(40.11,4.96);
glVertex2d(40.42,4.86);
glEnd();
}

void boatbody6(){
glColor3ub(178,190,181);
glBegin(GL_POLYGON);
glVertex2f(41.42,4.87);
glVertex2f(41.59,5.43);
glVertex2f(41.90,5.43);
glVertex2f(41.90,5.79);
glVertex2f(42.02,5.79);
glVertex2f(42.03,5.45);
glVertex2f(42.14,5.44);
glVertex2f(42.25,4.86);
glEnd();
}
void drawboat(){
glPushMatrix();
glTranslatef(_move2, 0.0f, 0.0f);
boat();
boatbody();
boatbody2();
boatbody3();
boatbody4();
boatbody5();
boatbody6();
glPopMatrix();

}


void plane(){
glColor3ub(74,93,35);
glBegin(GL_POLYGON);
glVertex2f(0.6370033491484, 16.7033594855373);
glVertex2f (0.690626900952, 16.7024965328684);
glVertex2f(0.3478754678289, 17.4554726162457);
glVertex2f(0.5213527537399, 17.4583742629414);

glColor3ub(85,107,47);
glVertex2f(1.7095033006314, 16.801553960615);
glVertex2f(1.906650929676, 16.7738632160236);
glVertex2f(3.8491829020347, 16.8106293739058);

glColor3ub(104,126,66);
glVertex2f(4.0911796617155, 16.7940708225821);
glVertex2f(4.4389537391284, 16.6431069182333);
glVertex2f(4.9277521371866, 16.5031224004796);

glColor3ub(94,140,49);
glVertex2f(4.9671137628584, 16.4342775556827);
glVertex2f(4.5877350493764, 16.3197297714654);

glColor3ub(75,105,46);
glVertex2f(1.0916545945685, 16.2956211714648);
glVertex2f(0.9598327855924, 16.377756298596);
glVertex2f(0.6381973630334, 16.4551619229155);


glEnd();
}

void planebody(){
glColor3ub(234,240,240);
glBegin(GL_POLYGON);
glVertex2f(3.8491829020347, 16.8106293739058);
glVertex2f(4.0911796617155, 16.7940708225821);
glVertex2f(4.4389537391284, 16.643106918233);
glVertex2f(3.9478605129103, 16.6912983095911);
glEnd();
}

void stand1(){


glColor3ub(1,50,32);
    glBegin(GL_POLYGON);
 glVertex2f   (1.507,16.2984);
 glVertex2f   (1.5944,16.299);
 glVertex2f   (1.5972899180597, 16.1748259144846);
 glVertex2f   (1.5073981266771, 16.1748259144846);
    glEnd();


glColor3ub(1,50,32);
    glBegin(GL_POLYGON);
 glVertex2f   (1.9655,16.30164);
 glVertex2f   (2.04389,16.302187);
glVertex2f(2.0467488749725, 16.1806253848961);
glVertex2f(1.9655562892076, 16.1806253848961);
glEnd();

}
void planemissile(){
 glColor3ub(100, 100, 100);
    glBegin(GL_POLYGON);
    glVertex2f(1.400229099321, 16.263343909361 - missileY2);
    glVertex2f(2.0699467566196, 16.2649115355717 - missileY2);
    glVertex2f(2.0698487799773, 16.2109989792832 - missileY2);
    glVertex2f(1.4019421045442, 16.2093842448336 - missileY2);
    glEnd();

    glColor3ub(167, 33, 29);
    glBegin(GL_POLYGON);
    glVertex2f(2.0699467566196, 16.2649115355717 - missileY2);
    glVertex2f(2.174531844593, 16.2345895290548 - missileY2);
    glVertex2f(2.0698487799773, 16.2109989792832 - missileY2);
    glEnd();
}

void building7(){
glColor3ub(255,87,51);
glBegin(GL_POLYGON);
glVertex2f(3.60,6.11);
glVertex2f(3.60,7.52);
glVertex2f(4.90,7.52);
glVertex2f(4.89,6.11);
glEnd();

}
void building11(){
glColor3ub(177,156,217);
glBegin(GL_POLYGON);
glVertex2f(3.60,6.11);
glVertex2f(3.60,7.52);
glVertex2f(4.90,7.52);
glVertex2f(4.89,6.11);
glEnd();

}
void drawbuilding1(){
glPushMatrix();
glTranslatef(2.0f, 0.0f, 0.0f);
building11();
glPopMatrix();
}
void building10(){
glColor3ub(255,87,51);
glBegin(GL_POLYGON);
glVertex2f(4.16,6.11);
glVertex2f(4.15,9.80);
glVertex2f(5.14,9.76);
glVertex2f(5.16,6.11);
glEnd();
}

void drawbuilding(){
glPushMatrix();
glTranslatef(1.16f, 0.0f, 0.0f);
building10();
glPopMatrix();
}

void drawplane(){
glPushMatrix();
glTranslatef(_move3, 0.0f, 0.0f);
plane();
planebody();
stand1();
glPopMatrix();
}


void w(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(3.84,7.45);
glVertex2f(3.95,7.46);
glVertex2f(3.95,7);
glVertex2f(3.84,7);
glEnd();
}

void w2(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(4.14,7.45);
glVertex2f(4.25,7.45);
glVertex2f(4.25,7.02);
glVertex2f(4.14,7);
glEnd();
}

void w3(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(4.51,7.47);
glVertex2f(4.62,7.46);
glVertex2f(4.62,7);
glVertex2f(4.51,7);
glEnd();
}

void w4(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(4.73,7.45);
glVertex2f(4.86,7.45);
glVertex2f(4.85,7);
glVertex2f(4.73,7);
glEnd();

}
void w5(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(4.15,6.90);
glVertex2f(4.26,6.90);
glVertex2f(4.27,6.46);
glVertex2f(4.14,6.46);
glEnd();

}
void w6(){
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(4.49,6.88);
glVertex2f(4.62,6.88);
glVertex2f(4.62,6.46);
glVertex2f(4.48,6.46);
glEnd();

}
void building8(){
glColor3ub(255,195,0);
glBegin(GL_POLYGON);
glVertex2f(4.16,6.11);
glVertex2f(4.15,9.80);
glVertex2f(5.14,9.76);
glVertex2f(5.16,6.11);
glEnd();

}
void airship(){
glColor3ub(68, 92, 78);
glBegin(GL_POLYGON);
glVertex2f(40.91,14.13);
glVertex2f(41.03,14.43);
glVertex2f(41.72,14.64);
glVertex2f(42.76,14.70);
glVertex2f(43.69,14.60);
glVertex2f(44.39,14.41);
glVertex2f(44.78,14.17);
glVertex2f(44.64,13.93);
glVertex2f(43.36,13.63);
glVertex2f(42.44,13.58);
glVertex2f(41.60,13.66);
glVertex2f(41.07,13.82);
glEnd();

}

void fan(){
glColor3ub(106,108,109);
glBegin(GL_POLYGON);
glVertex2f(44.6,14.8);
glVertex2f(44.2,14.8);
glVertex2f(44.06,14.50);
glVertex2f(44.61,14.28);
glEnd();
}
void fan2(){
glColor3ub(106,108,109);
glBegin(GL_POLYGON);
glVertex2f(44.11,13.81);
glVertex2f(44.21,13.64);
glVertex2f(44.61,13.64);
glVertex2f(44.61,14.93);
glEnd();

}
void fan3(){
glColor3ub(106,108,109);
glBegin(GL_POLYGON);
glVertex2f(43.96,14.17);
glVertex2f(44.53,14.17);
glVertex2f(44.54,14.11);
glVertex2f(43.96,14.10);
glEnd();

}
void stand(){
glColor3ub(1,50,32);
glBegin(GL_POLYGON);
glVertex2f(42.72,13.59);
glVertex2f(42.72,13.34);
glVertex2f(42.76,13.34);
glVertex2f(42.75,13.60);
glEnd();

}
void stand2(){
glColor3ub(1,50,32);
glBegin(GL_POLYGON);
glVertex2f(43.11,13.62);
glVertex2f(43.11,13.35);
glVertex2f(43.17,13.35);
glVertex2f(43.16,13.62);
glEnd();

}

void missile() {
    glBegin(GL_POLYGON);
    glColor3ub(186, 59, 61);
    glVertex2f(42.57, missileY);
    glVertex2f(42.63, missileY - 0.14);
    glVertex2f(43.37, missileY - 0.14);
    glVertex2f(43.39, missileY);
    glVertex2f(43.31, missileY + 0.13);
    glVertex2f(42.62, missileY + 0.13);
    glEnd();
}

void drawairship() {
glPushMatrix();
glTranslatef(_move4, 0.0f, 0.0f);
fan();
fan2();
fan3();
airship();
stand();
stand2();
glPopMatrix();
}

void truck(){
glColor3ub(189,183,107);
glBegin(GL_POLYGON);
glVertex2f(42.59,0.53);
glVertex2f(42.60,1.45);
glVertex2f(44.76,1.43);
glVertex2f(44.76,0.51);
glEnd();
}

void truckbody(){
glColor3ub(65,83,59);
glBegin(GL_POLYGON);
glVertex2f(41.59,0.79);
glVertex2f(41.93,0.92);
glVertex2f(42.09,1.26);
glVertex2f(42.56,1.26);
glVertex2f(42.55,0.51);
glVertex2f(44.77,0.50);
glVertex2f(44.73,0.32);
glVertex2f(43.46,0.37);
glVertex2f(43.36,0.37);
glVertex2f(43.40,0.30);
glVertex2f(42.31,0.30);
glVertex2f(42.29,0.38);
glVertex2f(41.61,0.38);
glEnd();
}

void tire(){
glBegin(GL_POLYGON);
float xOffa = 41.97;
float yOffa = 0.36;
for (int i = 0; i < 300; i++)
{
glColor3ub(66,71,86);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.24;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}

void tire2(){
glBegin(GL_POLYGON);
float xOffa = 43.75;
float yOffa = 0.34;
for (int i = 0; i < 300; i++)
{
glColor3ub(66,71,86);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.24;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}
void tire3(){
glBegin(GL_POLYGON);
float xOffa = 44.32;
float yOffa = 0.34;
for (int i = 0; i < 300; i++)
{
glColor3ub(66,71,86);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.25;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}

void drawtruck() {
glPushMatrix();
glTranslatef(_move5, 0.0f, 0.0f);
missile();
truckbody();
truck();
glPopMatrix();
}
void drawtire(){
glPushMatrix();
glTranslatef(_move5, 0.0f, 0.0f);
glRotatef(_angle1, 0.0f, 0.0f, 1.0f);
tire();
tire2();
tire3();
glPopMatrix();
}
void car(){
glColor3ub(139,180,217);
glBegin(GL_POLYGON);
glVertex2f(28.46,7.39);
glVertex2f(29.2,7.4);
glVertex2f(29.34,7.14);
glVertex2f(28.26,7.09);
glEnd();
}
void carbody(){
glColor3ub(93,132,166);
glBegin(GL_POLYGON);
glVertex2f(28.09,6.81);
glVertex2f(29.56,6.93);
glVertex2f(29.53,7.11);
glVertex2f(29.34,7.14);
glVertex2f(28.26,7.09);
glVertex2f(28.08,6.98);
glEnd();
}
void drawcar(){
glPushMatrix();
glTranslatef(_move7 ,0.0f, 0.0f);
car();
carbody();
glPopMatrix();
}
void cloud(){
glBegin(GL_POLYGON);
float xOffa = 14.36;
float yOffa = 16.67;
for (int i = 0; i < 300; i++)
{
glColor3ub(204,204,204);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.67;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}
void cloud2(){
glBegin(GL_POLYGON);
float xOffa = 15.13;
float yOffa = 17.22;
for (int i = 0; i < 300; i++)
{
glColor3ub(204,204,204);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.52;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}

void cloud3(){
glBegin(GL_POLYGON);
float xOffa = 15.23;
float yOffa = 16.31;
for (int i = 0; i < 300; i++)
{
glColor3ub(204,204,204);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.54;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}
void cloud4(){
glBegin(GL_POLYGON);
float xOffa = 16.14;
float yOffa = 16.37;
for (int i = 0; i < 300; i++)
{
glColor3ub(204,204,204);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.41;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}

void cloud5(){
glBegin(GL_POLYGON);
float xOffa = 16.12;
float yOffa = 17.26;
for (int i = 0; i < 300; i++)
{
glColor3ub(204,204,204);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.53;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}

void cloud6(){
glBegin(GL_POLYGON);
float xOffa = 16.95;
float yOffa = 16.67;
for (int i = 0; i < 300; i++)
{
glColor3ub(204,204,204);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.62;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}
void cloud7(){
glBegin(GL_POLYGON);
float xOffa = 15.65;
float yOffa = 16.79;
for (int i = 0; i < 300; i++)
{
glColor3ub(204,204,204);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.37;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}

void drawcloud(){
glPushMatrix();
glTranslatef(_move8 ,0.0f, 0.0f);
cloud();
cloud2();
cloud3();
cloud3();
cloud4();
cloud5();
cloud6();
cloud7();
glPopMatrix();
}

void helicopter(){
glBegin(GL_POLYGON);
glColor3ub(65,83,59);
glVertex2f(3.16f, 10.95f);
glVertex2f(3.34f, 10.95f);
glVertex2f(3.95f, 10.98f);
glVertex2f(4.27f, 11.06f);
glVertex2f(4.46f, 11.19f);
glVertex2f(4.49f, 11.26f);
glVertex2f(4.44f, 11.34f);
glVertex2f(4.15f, 11.51f);
glVertex2f(3.76f, 11.67f);
glVertex2f(3.61f, 11.67f);
glVertex2f(3.54f, 11.75f);
glVertex2f(3.36f, 11.76f);
glVertex2f(3.37f, 11.92f);
glVertex2f(3.32f, 11.92f);
glVertex2f(3.32f, 11.76f);
glVertex2f(3.15f, 11.75f);
glVertex2f(3.09f,11.66f);
glVertex2f(2.59,11.51);
glVertex2f(1.83f, 11.47f);
glVertex2f(1.42f, 11.95f);
glVertex2f(1.20f, 11.95f);
glVertex2f(1.41f, 11.31f);
glVertex2f(1.74f, 11.32f);
glEnd();
}
void helimissile(){
 glBegin(GL_POLYGON);
    glColor3ub(100,100,100);
    glVertex2f(1.9268697203535, missileY1);
    glVertex2f(2.4061680739517, missileY1);
    glVertex2f(2.4049698280677, missileY1 - 0.0553); // Adjust Y position for the second point
    glVertex2f(1.9280679662375, missileY1 - 0.0553); // Adjust Y position for the fourth point
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(167,33,29);
    glVertex2f(2.4061680739517, missileY1);
    glVertex2f(2.5080189740913, missileY1 - 0.028757); // Adjust Y position for the second point
    glVertex2f(2.4049698280677, missileY1 - 0.0553);   // Reuse the adjusted Y position
    glEnd();
}
void standh(){
        glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
glVertex2f(1.998,11.32);
glVertex2f(2.041,11.3243);
glVertex2f(2.0419013252171, 11.1578223434265);
glVertex2f(1.9999627192772, 11.1578223434265);
glEnd();
}
void standh2(){
         glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
glVertex2f(2.37815,11.32030);
glVertex2f(2.422,11.319);
glVertex2f(2.4229435163276, 11.1578223434265);
glVertex2f(2.3786084186198, 11.1590205893105);


glEnd();
}

void windows11(){
glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(3.51,11.49);
glVertex2f(3.76,11.50);
glVertex2f(3.77,11.29);
glVertex2f(3.51,11.31);
glEnd();
}

void windows12(){
glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(3.83,11.50);
glVertex2f(3.92,11.51);
glVertex2f(4.09,11.27);
glVertex2f(3.84,11.28);
glEnd();
}

void windows13(){
glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(3.92,11.56);
glVertex2f(3.96,11.57);
glVertex2f(4.42,11.34);
glVertex2f(4.47,11.27);
glVertex2f(4.17,11.27);
glVertex2f(4.01,11.50);
glEnd();

}

void blade(){
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(1.59,11.88);
glVertex2f(5.11,11.90);
glVertex2f(5.12,11.83);
glVertex2f(1.60,11.82);
glEnd();
}
void drawheli(){
glPushMatrix();
glTranslatef(_move9 ,0.0f, 0.0f);
helicopter();
windows11();
windows12();
windows13();
standh();
standh2();
//helimissile();
glPopMatrix();
}
void drawhelimissile(){
    glPushMatrix();
glTranslatef(_move ,0.0f, 0.0f);
helimissile();
glPopMatrix();
}

void drawblade(){
glPushMatrix();
glTranslatef(_move9, 0.0f, 0.0f);
glRotatef(_angle2, 1.0f, 0.0f, 0.0f);
blade();
glPopMatrix();
}
void wood(){
glBegin(GL_POLYGON);
glColor3ub(86,50,50);
glVertex2f(6.98,6.46);
glVertex2f(7.11,6.46);
glVertex2f(7.11,6.12);
glVertex2f(6.98,6.12);
glEnd();

}
void tree(){
glBegin(GL_POLYGON);
glColor3ub(61,183,36);
glVertex2f(6.98,6.4);
glVertex2f(6.8,6.4);
glVertex2f(6.9,6.5);
glVertex2f(6.83,6.49);

glVertex2f(6.93,6.60);
glVertex2f(6.87,6.60);
glVertex2f(6.97,6.70);
glVertex2f(6.91,6.71);

glVertex2f(7.07,7.92);
glVertex2f(7.24,6.71);
glVertex2f(7.26,6.59);
glVertex2f(7.2,6.6);

glVertex2f(7.26,6.49);
glVertex2f(7.2,6.5);
glVertex2f(7.3,6.4);
glVertex2f(7.11,6.40);

glEnd();

glBegin(GL_POLYGON);
glColor3ub(86,50,50);
glVertex2f(6.98 + 2.0,6.46);
glVertex2f(7.11 + 2.0,6.46);
glVertex2f(7.11 + 2.0,6.12);
glVertex2f(6.98 + 2.0,6.12);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(61,183,36);
glVertex2f(6.98 + 2.0,6.4);
glVertex2f(6.8 + 2.0,6.4);
glVertex2f(6.9 + 2.0,6.5);
glVertex2f(6.83 + 2.0,6.49);

glVertex2f(6.93 + 2.0,6.60);
glVertex2f(6.87 + 2.0,6.60);
glVertex2f(6.97 + 2.0,6.70);
glVertex2f(6.91 + 2.0,6.71);

glVertex2f(7.07 + 2.0,7.92);
glVertex2f(7.24 + 2.0,6.71);
glVertex2f(7.26 + 2.0,6.59);
glVertex2f(7.2 + 2.0,6.6);

glVertex2f(7.26 + 2.0,6.49);
glVertex2f(7.2 + 2.0,6.5);
glVertex2f(7.3 + 2.0,6.4);
glVertex2f(7.11 + 2.0,6.40);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(86,50,50);
glVertex2f(6.98 + 4.0,6.46);
glVertex2f(7.11 + 4.0,6.46);
glVertex2f(7.11 + 4.0,6.12);
glVertex2f(6.98 + 4.0,6.12);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(61,183,36);
glVertex2f(6.98 + 4.0,6.4);
glVertex2f(6.8 + 4.0,6.4);
glVertex2f(6.9 + 4.0,6.5);
glVertex2f(6.83 + 4.0,6.49);

glVertex2f(6.93 + 4.0,6.60);
glVertex2f(6.87 + 4.0,6.60);
glVertex2f(6.97 + 4.0,6.70);
glVertex2f(6.91 + 4.0,6.71);

glVertex2f(7.07 + 4.0,7.92);
glVertex2f(7.24 + 4.0,6.71);
glVertex2f(7.26 + 4.0,6.59);
glVertex2f(7.2 + 4.0,6.6);

glVertex2f(7.26 + 4.0,6.49);
glVertex2f(7.2 + 4.0,6.5);
glVertex2f(7.3 + 4.0,6.4);
glVertex2f(7.11 + 4.0,6.40);
glEnd();


}
void b11(){
glBegin(GL_POLYGON);
glColor3ub(117,134,165);
glVertex2f(7.48,6.12);
glVertex2f(7.43,8.89);
glVertex2f(8.07,8.84);
glVertex2f(8.16,6.11);
glEnd();

}
void w11(){
glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(7.56,8.64);
glVertex2f(7.70,8.63);
glVertex2f(7.70,8.20);
glVertex2f(7.56,8.20);
glEnd();

}
void w12(){
glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(7.82,8.63);
glVertex2f(8,8.60);
glVertex2f(8.01,8.20);
glVertex2f(7.82,8.20);
glEnd();

}
void w13(){
glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(7.5804079706106, 7.7190971779918);
glVertex2f(7.7058349744575, 7.7098062888183);
glVertex2f(7.7058349744575, 7.091962158783);
glVertex2f(7.5664716368499, 7.0873167141967);
glEnd();

}
void w14(){
glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(7.8544892012391, 7.7005153996449);
glVertex2f(8.0077888726075, 7.7005153996449);
glVertex2f(7.9938525388467, 7.1105439371304);
glVertex2f(7.8637800904129, 7.1058984925436);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(146,72,46);
glVertex2f(8.3,6.12);
glVertex2f(8.25,8.89);
glVertex2f(8.89,8.84);
glVertex2f(8.98,6.11);
glEnd();

glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(8.38,8.64);
glVertex2f(8.52,8.63);
glVertex2f(8.52,8.20);
glVertex2f(8.38,8.20);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(8.64,8.63);
glVertex2f(8.82,8.60);
glVertex2f(8.83,8.20);
glVertex2f(8.64,8.20);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(8.4044079706106, 7.7190971779918);
glVertex2f(8.5298349744575, 7.7098062888183);
glVertex2f(8.5298349744575, 7.091962158783);
glVertex2f(8.3904716368499, 7.0873167141967);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(8.6844892012391, 7.7005153996449);
glVertex2f(8.8377888726075, 7.7005153996449);
glVertex2f(8.8238525388467, 7.1105439371304);
glVertex2f(8.6937800904129, 7.1058984925436);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(235,195,113);
glVertex2f(9.1,6.12);
glVertex2f(9.05,8.89);
glVertex2f(9.69,8.84);
glVertex2f(9.78,6.11);
glEnd();

glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(9.18,8.64);
glVertex2f(9.32,8.63);
glVertex2f(9.32,8.20);
glVertex2f(9.18,8.20);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(9.44,8.63);
glVertex2f(9.62,8.60);
glVertex2f(9.63,8.20);
glVertex2f(9.44,8.20);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(9.2044079706106, 7.7190971779918);
glVertex2f(9.3298349744575, 7.7098062888183);
glVertex2f(9.3298349744575, 7.091962158783);
glVertex2f(9.1904716368499, 7.0873167141967);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(9.4644892012391, 7.7005153996449);
glVertex2f(9.6177888726075, 7.7005153996449);
glVertex2f(9.6038525388467, 7.1105439371304);
glVertex2f(9.4737800904129, 7.1058984925436);
glEnd();

}
void b12(){
glBegin(GL_POLYGON);
glColor3ub(93,93,93);
glVertex2f(9.80,6.14);
glVertex2f(9.8,7.2);
glVertex2f(10.43,7.20);
glVertex2f(10.42,6.14);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(9.89,6.76);
glVertex2f(10.05,6.76);
glVertex2f(10.06,7.01);
glVertex2f(9.90,7.01);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(10.2,7);
glVertex2f(10.32,7);
glVertex2f(10.32,6.75);
glVertex2f(10.19,6.75);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(93,93,93);
glVertex2f(10,7.20);
glVertex2f(10,9);
glVertex2f(10.29,9.25);
glVertex2f(10.29,7.20);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(10.0422861421918, 8.8924247479516);
glVertex2f(10.1481864814927, 8.8977197649165);
glVertex2f(10.1428914645276, 8.3258579327158);
glVertex2f(10.0475811591569, 8.3311529496806);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(10.1977311681254, 8.8916380146357);
glVertex2f(10.2662245519498, 8.894751350263);
glVertex2f(10.2662245519498, 8.3312376015507);
glVertex2f(10.2008445037538, 8.3312376015507);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(10.0620089456368, 7.9610209751132);
glVertex2f(10.1412915759451, 7.9654255656857);
glVertex2f(10.1368869853724, 7.4324701064133);
glVertex2f(10.0576043550641, 7.4324701064133);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(10.1846694397214, 7.9545745960743);
glVertex2f(10.2520039147706, 7.9571643835761);
glVertex2f(10.2468243397668, 7.4392068832197);
glVertex2f(10.1885449192187, 7.4472336908493);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(93,93,93);
glVertex2f(10.3541892418693, 6.1369590557533);
glVertex2f(10.3771214802941, 8.0411139660495);
glVertex2f(10.8974059277532, 8.4099231946281);
glVertex2f(10.9061955427148, 6.1354095223587);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(10.4800142075032, 7.8619787458233);
glVertex2f(10.601780303278, 7.8619787458233);
glVertex2f(10.6058391731371, 7.2937369655649);
glVertex2f(10.4776849538393, 7.2949015923968);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(10.7179071250972, 7.8766444408404);
glVertex2f(10.8220998740766, 7.8766444408404);
glVertex2f(10.8249941171038, 7.2977958354239);
glVertex2f(10.7265898541788, 7.2920073493697);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(125,116,116);
glVertex2f(11.0678658741515, 6.1727813261549);
glVertex2f(11.0849919472877, 8.8845980939568);
glVertex2f(12.6931223365357, 9.2280009374942);
glVertex2f(12.6978254804864, 6.1727813261549);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(11.3337129477123, 8.5784993393321);
glVertex2f(11.6893059915355, 8.5854717519558);
glVertex2f(11.6962784041595, 8.2438235333948);
glVertex2f(11.3337129477123, 8.2368511207712);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(12.2122369383344, 8.6342786403217);
glVertex2f(12.5329679190377, 8.6551958781928);
glVertex2f(12.5469127442857, 8.3205200722555);
glVertex2f(12.2261817635824, 8.3065752470081);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(11.3894922487042, 7.8812580769628);
glVertex2f(11.7381128799034, 7.8882304895865);
glVertex2f(11.7520577051514, 7.5047477952833);
glVertex2f(11.3894922487042, 7.4977753826596);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(12.1982921130864, 7.8812580769628);
glVertex2f(12.5259955064137, 7.8812580769628);
glVertex2f(12.5190230937897, 7.5674995088966);
glVertex2f(12.1982921130864, 7.5674995088966);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(118,63,63);
glVertex2f(12.8329751576496, 6.1703616902474);
glVertex2f(12.7903009223652, 10.8134163245357);
glVertex2f(14.8971688158509, 10.8247435712749);
glVertex2f(14.8940390340426, 6.1513657098206);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(13.0773962917936, 10.3612929015775);
glVertex2f(13.607461413274, 10.3820797690857);
glVertex2f(13.607461413274, 9.7480803100867);
glVertex2f(13.0981831593026, 9.7169000088244);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(14.0959527997363, 10.4028666365939);
glVertex2f(14.5220835836715, 10.413260070348);
glVertex2f(14.532477017426, 9.7792606113489);
glVertex2f(14.1271331009998, 9.7688671775948);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(13.1501503280752, 9.1452611523499);
glVertex2f(13.628248280783, 9.1764414536121);
glVertex2f(13.628248280783, 8.4385076570723);
glVertex2f(13.1917240630933, 8.4281142233182);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(14.1583134022634, 9.155654586104);
glVertex2f(14.532477017426, 9.166048019858);
glVertex2f(14.532477017426, 8.4592945245804);
glVertex2f(14.1583134022634, 8.4592945245804);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(159,175,145);
glVertex2f (14.99,6.11);
glVertex2f (14.9765148109511, 9.1632260196709);
glVertex2f (15.3661509853282, 9.1229188292181);
glVertex2f(15.3795867154791, 10.3993131935566);
glVertex2f(16.3738307466481, 10.3724417332547);
glVertex2f(16.4328238414868, 6.1279057587078);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(15.5, 10);
glVertex2f(15.7940577693588, 10.0031287542686);
glVertex2f(15.792763190954, 9.171822596325);
glVertex2f(15.5111926001261, 9.1799840627255);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(16.0786023936364, 10.0031287542686);
glVertex2f(16.2755948258285, 10.0031287542686);
glVertex2f(16.2824511750027, 9.1922262623262);
glVertex2f(16.0824952481828, 9.1963069955265);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(15.2338464850191, 8.7086756816748);
glVertex2f(15.5460395467507, 8.7194409596651);
glVertex2f(15.5568048247414, 7.8043923304901);
glVertex2f(15.2392291240145, 7.7936270524998);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(15.9671732158501, 8.6924673462152);
glVertex2f (16.2178129228657, 8.7063917743822);
glVertex2f(16.2247751369495, 8.0658680787022);
glVertex2f(15.9462865735988, 8.0658680787022);
glEnd();
}
void building12(){
    glBegin(GL_POLYGON);
    glColor3ub(118,63,63);
   glVertex2f (16.2315162431785, 7.9158403235774);
   glVertex2f (16.6904088128511, 8.0305634659955);
   glVertex2f (16.6998291192923, 6.2982956530276);
   glVertex2f (16.2269155494126, 6.2907864021763);
   glEnd();

    glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(16.5006397596516, 7.7524235302692);
glVertex2f(16.6192489748866, 7.7524235302692);
glVertex2f(16.6192489748866, 7.3610131200098);
glVertex2f(16.5085470406672, 7.3649667605175);
glEnd();

    glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(16.5164543216829, 7.2463575452874);
glVertex2f(16.611341693871, 7.2542648263027);
glVertex2f(16.6232026153945, 6.8984371806124);
glVertex2f(16.5204079621907, 6.890529899597);
glEnd();

glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
glVertex2f(17.3145329453561, 6.360781633443);
glVertex2f(17.9294187509669, 6.3709020056798);
glVertex2f(17.9294187509669, 7.2351496785631);
glVertex2f(17.2946173629199, 7.2275014690686);
glEnd();

   glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(17.3530154798419, 7.1113928194407);
glVertex2f(17.5695921198937, 7.1113928194407);
glVertex2f(17.5695921198937, 6.9489603394087);
glVertex2f(17.3560234887315, 6.9489603394087);
glEnd();

   glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(17.6804867673863, 7.1049751202388);
glVertex2f(17.8650049556473, 7.108424058337);
glVertex2f(17.8667294246965, 6.9566707820165);
glVertex2f(17.6856601745338, 6.9566707820165);
glEnd();


   glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(17.3631844623391, 6.8376824176288);
glVertex2f(17.5666718101411, 6.8394068866779);
glVertex2f(17.5718452172886, 6.6980004246519);
glVertex2f(17.3631844623391, 6.6980004246519);
glEnd();


   glBegin(GL_POLYGON);
glColor3ub(255,255,255);
glVertex2f(17.6804867673863, 6.8428558247761);
glVertex2f(17.8598315484998, 6.8480292319234);
glVertex2f(17.8650049556473, 6.6980004246519);
glVertex2f(17.6856601745338, 6.6945514865538);
glEnd();

glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
glVertex2f(17.9624333422405, 6.3678630396219);
glVertex2f(17.9464313636178, 7.3591732916525);
glVertex2f(18.6024713249223, 7.3705497071664);
glVertex2f(18.5821893183965, 6.3633060103857);
glEnd();

glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(18.0363732257087, 7.2700289013362);
glVertex2f(18.2218996078597, 7.2738541875659);
glVertex2f(18.2314628234345, 7.0500749431251);
glVertex2f(18.0459364412835, 7.0462496568953);
glEnd();

glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(18.3863869157462, 7.2757668306808);
glVertex2f(18.5489615805178, 7.2815047600255);
glVertex2f(18.5566121529776, 7.05198758624);
glVertex2f(18.3921248450911, 7.0539002293548);
glEnd();

glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(18.0546004908841, 6.959678158741);
glVertex2f(18.2384925111437, 6.959678158741);
glVertex2f(18.2426718752405, 6.7381718616193);
glVertex2f(18.0546004908841, 6.7444409077642);
glEnd();

glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f   (18.3868599365805, 6.9575884766927);
 glVertex2f   (18.5498551363561, 6.9575884766927);
  glVertex2f  (18.5561241825013, 6.7423512257159);
   glVertex2f (18.3889496186289, 6.7423512257159);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
  glVertex2f    (18.734672662361, 7.6293271829873);//build
  glVertex2f    (19.3921688491096, 7.6422192650804);
  glVertex2f    (19.374037535545, 6.3807886756153);
  glVertex2f    (18.7217805802679, 6.3873899413509);
 glEnd();

 glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
  glVertex2f    (18.8130282320281, 7.482758748062); //window
  glVertex2f    (19.0138420245571, 7.482758748062);
  glVertex2f    (19.0138420245571, 7.2960371515077);
  glVertex2f    (18.8095051830364, 7.2925141025162);
 glEnd();

 glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
  glVertex2f    (19.1582870332183, 7.4757126500788);
 glVertex2f     (19.3273933848217, 7.4862817970536);
  glVertex2f    (19.3309164338134, 7.2995602004993);
  glVertex2f    (19.1582870332183, 7.2995602004993);
 glEnd();

 glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
  glVertex2f    (19.1688561801936, 7.148069093861);
   glVertex2f   (19.32387033583, 7.148069093861);
   glVertex2f   (19.32387033583, 6.9648705462983);
   glVertex2f   (19.1618100822101, 6.9578244483152);
 glEnd();

 glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
  glVertex2f    (18.8165512810199, 7.1551151918442);
  glVertex2f    (19.0067959265737, 7.1586382408358);
  glVertex2f    (18.9997498285902, 6.9648705462983);
  glVertex2f    (18.8024590850529, 6.9648705462983);
 glEnd();
    //building
glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
  glVertex2f    (19.5225570080204, 7.5149061693879);
  glVertex2f    (20.0861735812283, 7.5149061693879);
   glVertex2f   (20.0970647227395, 6.3985641645301);
   glVertex2f   (19.5361709349095, 6.4012869499078);
 glEnd();
    //window
glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f  (19.6, 7.4);
 glVertex2f  (19.8, 7.4);
 glVertex2f  (19.8, 7.2);
 glVertex2f  (19.6, 7.2);
 glEnd();

 glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f  (19.8747232095129, 7.4023671450102);
 glVertex2f  (20.0550785010017, 7.4023671450102);
 glVertex2f  (20.0550785010017, 7.2039763243808);
 glVertex2f  (19.877299713677, 7.2065528285448);
 glEnd();

 glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f  (19.8726515529756, 7.1020130616647);
 glVertex2f  (20.0539849804376, 7.1020130616647);
 glVertex2f  (20.0559140594531, 6.8917434489782);
 glVertex2f  (19.8726515529756, 6.8936725279937);
 glEnd();

 glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
  glVertex2f (19.5964607597873, 7.093186645328);
  glVertex2f (19.7896985720967, 7.095763149492);
 glVertex2f  (19.7922750762608, 6.8870663122065);
 glVertex2f  (19.594864174736, 6.8840271329163);
 glEnd();

 //building

 glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
  glVertex2f (20.4015167897947, 6.3365762621043);
 glVertex2f  (20.3976938994658, 10.0660107255951);
 glVertex2f  (22.2736999059024, 10.0660107255951);
  glVertex2f (22.2704651451142, 6.353983442126);
 glEnd();
 //box
 glBegin(GL_POLYGON);
    glColor3ub(42,111,199);
  glVertex2f (20.6147073792959, 9.7968235223251);
 glVertex2f  (22.0660433155156, 9.8050231603825);
 glVertex2f  (22.0742429535733, 9.5016365522589);
  glVertex2f (20.6229070173537, 9.5098361903163);
  glEnd();

  glBegin(GL_POLYGON);
    glColor3ub(42,111,199);
  glVertex2f (20.6311066554114, 9.1900503060779);
  glVertex2f (22.0578436774579, 9.1982499441353);
  glVertex2f (22.0578436774579, 8.8046673173803);
 glVertex2f  (20.6475059315269, 8.8128669554377);
  glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(42,111,199);
 glVertex2f  (20.6343551966575, 8.4299051776943);
  glVertex2f (22.0578436774579, 8.4274839667401);
 glVertex2f  (22.0578436774579, 8.1240973586165);
 glVertex2f  (20.6475059315269, 8.1076980825017);
  glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(42,111,199);
  glVertex2f (20.6639052076424, 7.7961118363207);
  glVertex2f (22.0332447632847, 7.7961118363207);
  glVertex2f (22.0336997071482, 7.5467822701959);
  glVertex2f (20.6684855505719, 7.5425159759568);
  glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(42,111,199);
   glVertex2f (20.6639502273045, 7.1622693712177);
   glVertex2f (22.0145402674359, 7.1744368490562);
   glVertex2f (22.0084565285163, 6.8215799917394);
   glVertex2f (20.670033966224, 6.7972450360624);
    glEnd();
 ////building

  glBegin(GL_POLYGON);
    glColor3ub(224,164,0);
 glVertex2f  (22.5376652866945, 6.3946339265452);
 glVertex2f  (22.5258461268444, 8.9948490934414);
 glVertex2f  (25, 9);
 glVertex2f  (24.9960505354992, 6.4064530863947);
  glEnd();
 ////window
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f  (22.7740484836949, 8.7702850563003);
 glVertex2f  (23.5777513534964, 8.7702850563003);
 glVertex2f  (23.5777513534964, 8.202965383523);
 glVertex2f  (22.7858676435449, 8.202965383523);
  glEnd();
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f  (24.0032411080973, 8.7939233759994);
 glVertex2f  (24.7833056581988, 8.7939233759994);
 glVertex2f  (24.8069439778988, 8.2147845433725);
 glVertex2f  (24.0150602679473, 8.2266037032221);
  glEnd();
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f  (23.9704473645845, 7.8304219727867);
 glVertex2f  (24.7870770418807, 7.8304219727867);
 glVertex2f  (24.7870770418807, 7.3404441664295);
 glVertex2f  (24.0031125516764, 7.3513325621263);
  glEnd();
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f  (22.7509470464888, 7.8195335770899);
 glVertex2f  (23.5240231409959, 7.8195335770899);
 glVertex2f  (23.5240231409959, 7.3295557707327);
 glVertex2f  (22.7618354421861, 7.3295557707327);
 glEnd();
 //building
  glBegin(GL_POLYGON);
    glColor3ub(0, 184, 212);
 glVertex2f  (26.8000436305413, 6.3651270008332);
 glVertex2f  (26.822722433885, 9.0316945209184);
 glVertex2f  (27.6925505739216, 9.0152826692203);
 glVertex2f  (27.6761387222228, 6.3647686199744);
  glEnd();
 ////window
  glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f  (26.8970261982471, 8.8176867950136);
  glVertex2f (27.165514310042, 8.8150188547088);
 glVertex2f  (27.1585862672166, 8.4907367088154);
 glVertex2f  (26.8890115780928, 8.494191257346);
  glEnd();
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f  (27.3552507723535, 8.8174264171191);
  glVertex2f (27.6276486724177, 8.8174264171191);
 glVertex2f  (27.6193165036992, 8.5047447967329);
  glVertex2f (27.3554780190148, 8.5005233809781);
  glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
  glVertex2f (27.3580882504791, 8.3322176576499);
  glVertex2f (27.6135848345746, 8.3366938377932);
  glVertex2f (27.616298759915, 8.0257700200905);
  glVertex2f (27.3552975748123, 8.0224443384289);
  glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f  (26.8703238784637, 8.3235851929088);
 glVertex2f  (27.1501350765395, 8.3235851929088);
  glVertex2f (27.1566273035566, 8.0257700200905);
  glVertex2f (26.8645517812639, 8.0245967322602);
 glEnd();

    glBegin(GL_POLYGON);
   glColor3ub(121, 85, 72);
  glVertex2f  (25.2, 8.8);
  glVertex2f  (26.5117937405315, 8.8095704765022);
  glVertex2f  (26.5504381271786, 6.3462283122293);
  glVertex2f  (25.199219289702, 6.3437092919489);
  glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
  glVertex2f  (25.3545528941046, 8.6094346219585);
  glVertex2f  (25.758644437, 8.6129181697419);
  glVertex2f  (25.7621279847836, 8.3551356337677);
  glVertex2f  (25.3545528941046, 8.3516520859843);
  glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
   glVertex2f (26.0686801897387, 8.605951074175);
   glVertex2f (26.4, 8.6);
  glVertex2f (26.406584324746, 8.3621027293346);
  glVertex2f  (26.0651966419551, 8.365586277118);
 glEnd();

 // building
 glBegin(GL_POLYGON);
   glColor3ub(39,157,37);
 glVertex2f(27.7689302289988, 6.3932579373657);
 glVertex2f(27.7689302289988, 7.3965731175579);
 glVertex2f(28.1392389863723, 7.4440485992705);
 glVertex2f(28.1424040184866, 6.3900929052516);
 glEnd();

 //window
 glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f (27.8379669183078, 7.287339097555);
 glVertex2f(27.9486688024511, 7.287339097555);
 glVertex2f(27.9486688024511, 7.0105843872083);
glVertex2f (27.8464824478573, 7.0063266224337);
 glEnd();

 //window
  glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f (28.0144421449051, 7.2802001976859);
glVertex2f (28.0965926097046, 7.2802001976859);
glVertex2f (28.1, 7);
glVertex2f (28.0068799171827, 6.9992415461776);
 glEnd();

 //building
 glBegin(GL_POLYGON);
   glColor3ub(24,22,16);
 glVertex2f(28.2051328470424, 7.6083958296706);
 glVertex2f(28.5848770974868, 7.6134590863429);
glVertex2f (28.5798138408142, 6.3780244582824);
 glVertex2f(28.2203226170602, 6.37296120161);
 glEnd();

 //window
  glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f (28.2401045840342, 7.5021158551589);
glVertex2f (28.3, 7.5);
glVertex2f (28.3014915744458, 7.1870731873996);
glVertex2f (28.2412628291364, 7.1905479227058);
 glEnd();

  //window
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f  (28.4763865848636, 7.4997993649548);
glVertex2f  (28.5447230458878, 7.4997993649548);
 glVertex2f (28.5447230458878, 7.194022658012);
 glVertex2f (28.4775448299657, 7.1917061678078);
  glEnd();

  //building
  glBegin(GL_POLYGON);
   glColor3ub(60,98,102);
 glVertex2f (28.6304464075401, 8.2109233736837);
 glVertex2f (29.0314975150359, 8.1987425594168);
 glVertex2f (29.0390622409024, 6.3945554403235);
 glVertex2f (28.6532612217091, 6.3869907144573);
  glEnd();

  //window
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (28.679581843213, 8.0761039975699);
 glVertex2f (28.7930517269299, 8.0761039975699);
 glVertex2f (28.7955732799014, 7.67517707512);
 glVertex2f (28.67453873727, 7.6726555221487);
  glEnd();

  //window
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f  (28.8560905512171, 8.0609746797416);
glVertex2f  (28.9670388819626, 8.063496232713);
glVertex2f  (28.9670388819626, 7.6776986280914);
 glVertex2f (28.8636552101316, 7.6776986280914);
  glEnd();

  //building
  glBegin(GL_POLYGON);
   glColor3ub(122,130,229);
glVertex2f  (29.0722452374207, 8.0827026849692);
 glVertex2f (29.4608991374119, 8.0767233942003);
glVertex2f  (29.4429612651046, 6.4025219789238);
 glVertex2f (29.0988715855796, 6.3974457498491);
  glEnd();

  //window
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (29.125629037775, 8.0067249063198);
glVertex2f  (29.1600541319293, 8.0090199125966);
glVertex2f  (29.1623491382063, 7.5718212168544);
glVertex2f  (29.1279240440519, 7.5695262105775);
  glEnd();

  //window
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f  (29.2128392762994, 8.0136099251504);
glVertex2f  (29.2426743578998, 8.0136099251504);
glVertex2f  (29.2472643704538, 7.5718212168544);
 glVertex2f (29.2139867794379, 7.570673713716);
  glEnd();

  //window
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (29.288574483439, 8.0136099251504);
glVertex2f  (29.3184095650395, 8.0136099251504);
 glVertex2f (29.3218520744549, 7.578706235685);
glVertex2f  (29.290869489716, 7.5775587325465);
  glEnd();

  //window
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f  (29.3620146843017, 8.0136099251504);
 glVertex2f (29.3964397784561, 8.0147574282888);
 glVertex2f (29.4044723004254, 7.5821487451003);
 glVertex2f (29.3654571937171, 7.5798537388234);
  glEnd();

  //box
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (29.1407144448492, 8.2749011554626);
glVertex2f  (29.3933584595638, 8.2702225625977);
glVertex2f  (29.388,8.077);
glVertex2f  (29.138,8.081);
  glEnd();

  //line
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f  (29.1717771746726, 8.2574559252033);
 glVertex2f (29.1685269764645, 8.1022589607745);
  glEnd();

  //line 2
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (29.2132172018255, 8.2598935738592);
 glVertex2f (29.2107795531694, 8.0998213121186);
  glEnd();

  //line3
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (29.2595325262904, 8.2566433756513);
glVertex2f  (29.2579074271864, 8.1063217085344);
  glEnd();

  //line4
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f  (29.3147858958276, 8.2574559252033);
glVertex2f  (29.3139733462755, 8.1063217085344);
  glEnd();

  //line5
   glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f  (29.3635388689486, 8.2558308260993);
glVertex2f  (29.3619137698445, 8.1046966094305);
  glEnd();

  //triangle
   glBegin(GL_POLYGON);
    glColor3ub(100,100,100);
 glVertex2f (29.234,8.273);
 glVertex2f (29.2601447761118, 8.670454421292);
 glVertex2f (29.297,8.2719);
  glEnd();

  //buildong
  glBegin(GL_POLYGON);
   glColor3ub(142,196,168);
glVertex2f  (29.6590505448486, 8.2346098927373);
 glVertex2f (30.4430978011182, 8.2540893276749);
 glVertex2f (30.4382279423836, 6.4327621610131);
 glVertex2f (29.6590505448486, 6.4278923022787);
  glEnd();

  //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (29.7515778608059, 8.117733283112);
 glVertex2f (29.9074133403129, 8.1226031418463);
 glVertex2f (29.9122831990475, 7.8791102051269);
glVertex2f  (29.7515778608059, 7.8791102051269);
  glEnd();

  //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (30.2093445818577, 8.1323428593151);
 glVertex2f (30.3554403438955, 8.1323428593151);
  glVertex2f(30.3457006264263, 7.8645006289237);
 glVertex2f (30.2044747231231, 7.8596307701893);
  glEnd();


  //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (30.1971940617595, 7.7158763868405);
 glVertex2f (30.3321442756383, 7.7190147639073);
 glVertex2f (30.3384210297722, 7.4365608278937);
 glVertex2f (30.1971940617595, 7.4334224508269);
  glEnd();

  //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (29.7564477195405, 7.6989254319544);
 glVertex2f (29.9171530577821, 7.7037952906888);
 glVertex2f (29.9164844455385, 7.4156514429016);
 glVertex2f (29.7619550439669, 7.4156514429016);
  glEnd();

  //building
  glBegin(GL_POLYGON);
   glColor3ub(156,0,47);
 glVertex2f (30.6751725795785, 8.2562383986837);
 glVertex2f (31.9960824952653, 8.2904842113112);
 glVertex2f (31.9765134594773, 6.4363180704802);
 glVertex2f (30.6751725795785, 6.4020722578528);
  glEnd();

  //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (30.7925867943062, 8.114362889227);
glVertex2f  (31.0763378132315, 8.1290396660674);
glVertex2f  (31.0861223311255, 7.8403963882071);
glVertex2f  (30.8012866885547, 7.8402747466812);
  glEnd();

  //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f  (31.5362101542484, 8.1290396660674);
glVertex2f  (31.8884527984315, 8.1535009608013);
glVertex2f  (31.9031295752725, 7.8599654239943);
 glVertex2f (31.5459946721424, 7.8501809061007);
  glEnd();

  //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (31.5830991778373, 7.6310526341684);
 glVertex2f (31.8746418356104, 7.6504888113525);
  glVertex2f(31.8894098019934, 7.334730822317);
 glVertex2f (31.5860834473623, 7.3299161182755);
  glEnd();

  //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (30.8205455047217, 7.5706513203536);
 glVertex2f (31.0901689310605, 7.5850954324783);
 glVertex2f (31.0997983391441, 7.3010278940261);
 glVertex2f (30.834989616847, 7.3010278940261);
  glEnd();

  //building
  glBegin(GL_POLYGON);
   glColor3ub(156,147,138);
 glVertex2f (35, 10);
  glVertex2f(37, 10);
  glVertex2f(37.0043325416182, 6.4204566090627);
  glVertex2f(34.9811688227285, 6.4098641288596);
  glEnd();

  //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f  (35.205818652324, 9.7625132897501);
glVertex2f  (36.8029110111833, 9.7719079506842);
 glVertex2f (36.8029110111833, 9.3867268523871);
 glVertex2f (35.2246079741929, 9.3961215133212);
  glEnd();

  //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f  (35.2433972960618, 9.1330710071672);
 glVertex2f (36.7841216893144, 9.1236763462331);
 glVertex2f (36.7841216893144, 8.7760738916724);
  glVertex2f(35.2527919569963, 8.7854685526064);
  glEnd();

  //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f  (35.2809759397997, 8.4942340636501);
glVertex2f  (36.7841216893144, 8.4848394027161);
glVertex2f  (36.7841216893144, 8.1090529653531);
glVertex2f  (35.2809759397997, 8.1184476262872);
  glEnd();

  //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (35.2809759397997, 7.8929757638694);
 glVertex2f (36.8217003330522, 7.8929757638694);
 glVertex2f (36.844,7.5235);
 glVertex2f (35.2809759397997, 7.5265839874406);
  glEnd();

  //b
  glBegin(GL_POLYGON);
   glColor3ub(231,135,87);
 glVertex2f (37.2476475796944, 9.5713936021017);
 glVertex2f (38.4788712431585, 9.5809379715856);
  glVertex2f(38.545681829548, 6.4026629334742);
glVertex2f  (37.1999257322733, 6.3644854555389);
  glEnd();


  //w
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f  (37.3559179014763, 9.2914346820868);
glVertex2f  (37.6556240147124, 9.2914346820868);
glVertex2f  (37.6694036061256, 8.9813938753038);
glVertex2f  (37.3593627993296, 8.9710591817444);
  glEnd();

  //w
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f  (38.0483423699873, 9.2845448863805);
 glVertex2f (38.3652729724898, 9.2914346820868);
 glVertex2f (38.3652729724898, 8.984838773157);
 glVertex2f (38.0517872678406, 8.9745040795976);
  glEnd();

  //w
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f  (38.0727626960241, 8.7178529642305);
glVertex2f  (38.3865221727413, 8.7253234279616);
glVertex2f  (38.3641107815472, 8.3816820963332);
glVertex2f  (38.0652922322927, 8.3891525600643);
  glEnd();


  //w
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
 glVertex2f (37.3555981778132, 8.6543540225166);
 glVertex2f (37.6618871907991, 8.6543540225166);
 glVertex2f (37.6469462633363, 8.3630059370056);
  glVertex2f(37.3481277140818, 8.3592707051401);
  glEnd();

//building
glBegin(GL_POLYGON);
   glColor3ub(229,220,123);
glVertex2f(38.709,8.659);
glVertex2f(39.6027966327232, 9.5152160367242);
glVertex2f(39.6027966327232, 6.2613635460979);
glVertex2f(38.6814417883466, 6.2601834798452);
glEnd();

//window;
  glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(38.8600903857192, 8.4817915677284);
glVertex2f(39.4310295729532, 8.4677520795183);
glVertex2f(39.4310295729532, 8.2852387327872);
glVertex2f(38.8554105563156, 8.2899185621906);
glEnd();

//window
  glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(38.8554105563156, 8.1869623153166);
glVertex2f(39.4263497435497, 8.19164214472);
glVertex2f(39.4310295729532, 7.9810498215687);
glVertex2f(38.8647702151227, 7.9904094803754);
glEnd();
//window
  glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(38.8600903857192, 7.9014927217115);
glVertex2f(39.4310295729532, 7.8968128923081);
glVertex2f(39.4450690611639, 7.7189793749804);
glVertex2f(38.8741298739299, 7.7096197161737);
glEnd();

//window
  glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(38.8600903857192, 7.6207029575098);
glVertex2f(39.4344736715023, 7.6181744560252);
glVertex2f(39.4316614082952, 7.4325650843647);
glVertex2f(38.863584240462, 7.4297528211578);
glEnd();

//window
  glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(38.8593737774412, 7.3329415605721);
glVertex2f(39.442931388141, 7.3329415605721);
glVertex2f(39.4469283580773, 7.1410870036377);
glVertex2f(38.8593737774412, 7.1370900337016);
glEnd();

//b
glBegin(GL_POLYGON);
   glColor3ub(133,163,159);
glVertex2f(39.7843355640669, 8.6419680359718);
glVertex2f(40.4986914349722, 8.6364729908112);
glVertex2f(40.4822062994897, 6.284593662083);
glVertex2f(39.7843355640669, 6.284593662083);
glEnd();

//window
  glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(39.8815664521173, 8.5077241213314);
glVertex2f(40.0955317604177, 8.5077241213314);
glVertex2f(40.0955317604177, 8.0132265199467);
glVertex2f(39.9053403752618, 8.0179813045754);
glEnd();

//window
  glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(40.2429300839135, 8.498214552074);
glVertex2f(40.4128033549493, 8.4944018185836);
glVertex2f(40.4160664088322, 8.0289391461725);
glVertex2f(40.2544037314496, 8.0241843615438);
glEnd();

//window
  glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(40.2762135763158, 7.8420542733135);
glVertex2f(40.4188571151828, 7.8325447040561);
glVertex2f(40.4331214690695, 7.4521619337602);
glVertex2f(40.2857231455736, 7.4521619337602);
glEnd();

//window
  glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(39.895830806004, 7.8372994886848);
glVertex2f(40.0955317604177, 7.8420542733135);
glVertex2f(40.1050413296755, 7.4521619337602);
glVertex2f(39.9053403752618, 7.4474071491315);
glEnd();

//building
glBegin(GL_POLYGON);
   glColor3ub(216,194,166);
glVertex2f(43.7730008533412, 9.2429066517441);
glVertex2f(44.8372798268479, 8.5444735754096);
glVertex2f(44.87053854477, 6.3383119533371);
glVertex2f(43.7619146140338, 6.349398192644);
glEnd();

//window;
 glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(43.8918771348153, 8.4162187270959);
glVertex2f(44.2020937881739, 8.4162187270959);
glVertex2f(44.1972140566282, 8.0082952161968);
glVertex2f(43.8869974032695, 8.0020908831298);
glEnd();

//window
 glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(44.5074307099868, 8.4053725324792);
glVertex2f(44.7183780342707, 8.4053725324792);
glVertex2f(44.7245823673379, 8.0020908831298);
glVertex2f(44.510,8.008);
glEnd();

//window
 glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(44.4950220438525, 7.7353045612526);
glVertex2f(44.727,7.7326);
glVertex2f(44.7307867004051, 7.3630445772378);
glVertex2f(44.5074307099868, 7.3630445772378);
glEnd();

//window
 glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(43.8869974032695, 7.6980785628511);
glVertex2f(44.191009723561, 7.7104872289849);
glVertex2f(44.1848053904938, 7.3506359111039);
glVertex2f(43.8869974032695, 7.3506359111039);
glEnd();



}
void tree2(){
       glBegin(GL_POLYGON);
       glColor3ub(161,102,47);
      glVertex2f (16.9196151664123, 6.3971841542562);
       glVertex2f(17.1, 6.4);
      glVertex2f (17.1129658974924, 6.130370716061);
      glVertex2f (16.9250238789561, 6.130370716061);
       glEnd();

        glBegin(GL_POLYGON);
          glColor3ub(0,128,0);
        glVertex2f  (17.0102413239299, 7.2414383927954);
        glVertex2f  (17.1686204238089, 7.033565824213);
        glVertex2f  (17.0911092602775, 7.0300589294036);
        glVertex2f  (17.2447724926437, 6.8155152172265);
       glVertex2f   (17.1706138042049, 6.8041061882364);
       glVertex2f   (17.3265372004095, 6.5987436664146);
       glVertex2f   (17.2428709878119, 6.5911376470879);
         glVertex2f (17.4, 6.4);
         glVertex2f (16.6400939561432, 6.3876766300978);
          glVertex2f(16.7770023040301, 6.5930391519196);
           glVertex2f (16.6981,6.5999);
            glVertex2f  (16.8598184814463, 6.8113925416147);
        glVertex2f (16.783568385639, 6.8113925416147);
       glVertex2f   (16.9287621272114, 7.0214462248706);
           glVertex2f  (16.8546661415843, 7.0248925497833);
          glEnd();

          glBegin(GL_POLYGON);
       glColor3ub(161,102,47);
         glVertex2f (25.6434628240483, 6.5349806579465);
         glVertex2f (25.8304524470597, 6.5349806579465);
         glVertex2f (25.8400416584962, 6.1705906233754);
         glVertex2f (25.6434628240483, 6.1705906233754);
          glEnd();

             glBegin(GL_POLYGON);
          glColor3ub(0,128,0);
         glVertex2f (25.7132229756515, 8.1977554343737);
         glVertex2f (25.4813659836803, 7.8513666752986);
        glVertex2f  (25.6294192436137, 7.8401928443607);
        glVertex2f  (25.4130934519059, 7.5219847807042);
        glVertex2f  (25.5422950078887, 7.5349049363019);
        glVertex2f  (25.3312657997835, 7.1731405795653);
       glVertex2f   (25.4690807928318, 7.1731405795653);
       glVertex2f   (25.2279045549973, 6.8372165340241);
      glVertex2f    (25.3614128295128, 6.8286030969589);
       glVertex2f   (25.1393427341835, 6.479405409806);
       glVertex2f   (26.3277756282492, 6.4840270022128);
       glVertex2f   (26.1084619055821, 6.844328118008);
       glVertex2f   (26.2416166657729, 6.8129975861997);
       glVertex2f   (26, 7.2);
       glVertex2f   (26.1750392856775, 7.1732987019948);
       glVertex2f   (25.928311347677, 7.5179345518858);
       glVertex2f   (26.0692987408201, 7.5179345518858);
        glVertex2f  (25.847308946912, 7.8429863020952);
        glVertex2f  (25.9945004538284, 7.8449886706476);
          glEnd();

       glBegin(GL_POLYGON);
          glColor3ub(0,128,0);
         glVertex2f (37.7782077074909, 8.6676184476716);
          glVertex2f(38.5488291807436, 6.8104685618982);
        glVertex2f  (37.0745967971298, 6.7961091555649);
          glEnd();

    glBegin(GL_POLYGON);
       glColor3ub(161,102,47);
        glVertex2f  (37.5398369955531, 6.9530385349289);
        glVertex2f  (38.0031717400554, 6.9540626252312);
        glVertex2f  (37.9982782800854, 6.1548011956746);
         glVertex2f (37.5349435355831, 6.1606757985964);
          glEnd();

}
void boat2(){
glColor3ub(55,55,55);
glBegin(GL_POLYGON);
glVertex2f(0.2098463093678, 5.6781061231613);
glVertex2f(0.3374393849848, 5.3178433214343);
glVertex2f(3.1745089487038, 5.2878214212904);
glVertex2f(3.6374640915587, 5.7584470894943);
glVertex2f(2.7135338065931, 5.7699962180559);
glVertex2f(2.6488986219446, 5.7101753681875);
glVertex2f(1.0611971042377, 5.7188401707167);
glVertex2f(0.9880358973896, 5.6456789638716);
glVertex2f(0.2098463093678, 5.6781061231613);
glEnd();

glColor3ub(73,47,47);
glBegin(GL_POLYGON);
glVertex2f(1.10,5.71);
glVertex2f(1.1777913121352, 5.9405088775958);
glVertex2f(1.9739416242557, 5.9339291229504);
glVertex2f(2.0611823438842, 6.0570710441546);
glVertex2f(2.4900483013183, 6.0531306774401);
glVertex2f(2.62,5.71);
glEnd();

glColor3ub	(182,186,199);
glBegin(GL_POLYGON);
glVertex2f(1.82,5.93);
glVertex2f(1.9, 6.3);
glVertex2f(2, 6.3);
glVertex2f(2.0011716511847, 6.5523747476577);
glVertex2f(2.0518331941661, 6.5538647930394);
glVertex2f(2.0533232395479, 6.3154575319604);
glVertex2f(2.2634196383826, 6.3080073050517);
glVertex2f(2.3810755298123, 5.9299825999397);
glEnd();

glColor3ub	(182,186,199);
glBegin(GL_POLYGON);
glVertex2f(2.75,5.76);
glVertex2f(2.8250355332887, 5.9507310919713);
glVertex2f(3.0593797321436, 5.9507310919713);
glVertex2f(3.064125140714, 5.9154150266965);
glVertex2f(3.2801518375037, 5.9874239256234);
glVertex2f(3.2927849776669, 5.9318381089079);
glVertex2f(3.10,5.76);
glEnd();

glColor3ub	(182,186,199);
glBegin(GL_POLYGON);
glVertex2f(1.69,5.93);
glVertex2f(1.6376826735243, 6.1397525173003);
glVertex2f (1.390477838085, 6.1351058098674);
glVertex2f(1.3861381352024, 6.0923477736498);
glVertex2f(1.1799372292525, 6.1741464801389);
glVertex2f(1.161191692348, 6.1179098694276);
glVertex2f(1.3690967380164, 6.037815302657);
glVertex2f(1.3447571546527, 5.9407418983864);
glEnd();
}

void drawboat2(){
glPushMatrix();
glTranslatef(_move10, 0.0f, 0.0f);
planemissile();
boat2();
glPopMatrix();
}

void fire3 (){
      glColor3ub(255,37,0);
    glBegin(GL_POLYGON);
 glVertex2f (0.647961257319, 6.0439973751538);
 glVertex2f (0.7457646966847, 5.9137850973277);
 glVertex2f (0.7492668239337, 5.7737000073733);
glColor3ub(255,219,0);
 glVertex2f (0.778820005451, 5.7491851166313);
 glVertex2f (0.8171603769455, 5.7661313431558);
 glVertex2f (0.8268886797804, 5.8510328951659);
 glColor3ub(255,102,0);
 glVertex2f (0.8702238469541, 5.7979694251596);
 glVertex2f (0.8960339257859, 5.7168520345487);
 glVertex2f (0.8948048744129, 5.6345055925649);
glColor3ub(234,92,15);
 glVertex2f (0.8654110546018, 5.5478717655782);
 glVertex2f (0.7447851900435, 5.4666812798211);
 glVertex2f (0.6056015001684, 5.4713207361501);
 glColor3ub(255,219,0);
 glVertex2f (0.5113408460545, 5.5521591505811);
 glVertex2f (0.4769274076121, 5.6381927466836);
 glVertex2f (0.4855307672227, 5.7328297023963);
 glColor3ub(242,242,23);
 glVertex2f (0.5531285927346, 5.849589582821);
 glVertex2f (0.629828459354, 5.9505437241075);
glEnd();

  glColor3ub(255,37,0);
    glBegin(GL_POLYGON);
  glVertex2f (1.7687016382252, 5.8453432511585);
  glVertex2f (2.0434003645261, 5.5157047796113);
glColor3ub(255,219,0);
  glVertex2f (2.9224362886887, 5.5193674292952);
  glVertex2f (3.2340825847439, 5.7373463627664);
 glColor3ub(255,102,0);
  glVertex2f (3.1806214029832, 6.2913986100808);
  glVertex2f (2.9663880848969, 5.8233673530553);
glColor3ub(234,92,15);
  glVertex2f (2.8963051181652, 6.2573778580528);
  glVertex2f (2.7100026070161, 5.8526685505262);
   glColor3ub(255,219,0);
  glVertex2f (2.4734757715128, 6.2962587175134);
  glVertex2f (2.2156992882338, 5.9025598908414);
  glColor3ub(242,242,23);
  glVertex2f (2.0365079305105, 6.3494588191205);
glEnd();

}

void cloud77(){
glBegin(GL_POLYGON);
float xOffa = 41.1818819041431;
float yOffa = 15.700390754591;
for (int i = 0; i < 300; i++)
{
glColor3ub(204,204,204);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = -0.512;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}

void cloud79(){
glBegin(GL_POLYGON);
float xOffa = 42.0250468221559;
float yOffa = 15.6401646890211;
for (int i = 0; i < 300; i++)
{
glColor3ub(204,204,204);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = -0.4818;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}
void cloud80(){
glBegin(GL_POLYGON);
float xOffa = 42.7598481094521;
float yOffa = 15.5276920662786;
for (int i = 0; i < 300; i++)
{
glColor3ub(204,204,204);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.501;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}

void cloud81(){
glBegin(GL_POLYGON);
float xOffa = 43.6399450309261;
float yOffa =  15.7300131976434;
for (int i = 0; i < 300; i++)
{
glColor3ub(204,204,204);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.509;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}

void cloud82(){
glBegin(GL_POLYGON);
float xOffa = 41.6842752472389;
float yOffa =  16.3522911454512;
for (int i = 0; i < 300; i++)
{
glColor3ub(204,204,204);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.4686;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}
void cloud83(){
glBegin(GL_POLYGON);
float xOffa = 42.4414536844181;
float yOffa =  16.308179712413;
for (int i = 0; i < 300; i++)
{
glColor3ub(204,204,204);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.4668;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}

void cloud84(){
glBegin(GL_POLYGON);
float xOffa = 43.1392290352443;
float yOffa =  16.0925655915543;
for (int i = 0; i < 300; i++)
{
glColor3ub(204,204,204);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = 0.4818;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}

void drawcloud2(){
     glPushMatrix();
glTranslatef(_move12, 0.0f, 0.0f);
cloud77();
cloud79();
cloud79();
cloud80();
cloud81();
cloud82();
cloud83();
cloud84();
glPopMatrix();
}



void drawboatfire(){
    if (!missileFalling2) {
    glPushMatrix();
glTranslatef(_move10, 0.0f, position7);
fire3();
glPopMatrix();
}
}
void fire(){
   glColor3ub(255,37,0);
    glBegin(GL_POLYGON);
       glVertex2f (42, 1.5);
    glVertex2f(42.1043798100504, 2.1548358469498);
   glVertex2f (42.682676503088, 1.6272550495437);
   glColor3ub(255,219,0);
    glVertex2f(42.8381951482505, 2.0983850628105);
    glVertex2f(43.2, 1.6);
       glColor3ub(255,102,0);
    glVertex2f(43.4099548731128, 2.1166813740053);
    glVertex2f(43.7347143968345, 1.5769401937579);
    glVertex2f(43.8399181862092, 1.9520145732519);
          glColor3ub(234,92,15);
   glVertex2f (44.3476408218869, 1.5220512601734);
   glVertex2f (44.6678262678097, 1.9520145732519);
      glColor3ub(255,219,0);
   glVertex2f (44.6769744234075, 1.0554953247053);
   glVertex2f (44.2653074215067, 0.872532212757);
      glColor3ub(242,242,23);
    glVertex2f(43.8399181862092, 0.8039210457764);
    glVertex2f(43.2269917611568, 0.8862544461531);
   glVertex2f (42.7146950476803, 0.8359395903674);
    glVertex2f(42.234416878796, 0.8450877459648);
    glEnd();
}

void drawfire() {
    if (truckHit) { // Only draw fire if truck is hit
        glPushMatrix();
        glTranslatef(_move5, 0.0f, position7);
        fire();
        glPopMatrix();
    }
}
void fire2(){
        glBegin(GL_POLYGON);
       glColor3ub(255,37,0);
         glVertex2f (0.9665151348401, 2.1594132901308);
         glVertex2f (0.6646483024508, 2.6808196369632);
         glColor3ub(255,219,0);
          glVertex2f(0.806434238876, 3.3211432207925);
         glVertex2f (1.1677596897663, 2.900359151419);
           glColor3ub(255,102,0);
          glVertex2f(1.346135545269, 3.2845533017166);
         glVertex2f (1.7028872562746, 2.7082620762702);
          glColor3ub(234,92,15);
         glVertex2f (1.9315742505089, 3.2571108624096);
          glVertex2f(2.1145238458963, 2.7036883363857);
            glColor3ub(255,219,0);
             glVertex2f (2.6, 3.2);
         glVertex2f (2.7091100309056, 2.7311307756927);
           glColor3ub(242,242,23);
          glVertex2f(2.3798007592082, 2.1456920704773);
          glEnd();
}
void cargo(){
    glBegin(GL_POLYGON);
glColor3ub(65,83,59);
   glVertex2f (45.9689166814109, 13.8410050103239);
  glVertex2f  (45.8096838378679, 14.0002378538603);
   glVertex2f (45.9954554886681, 14.1506244283113);
  glVertex2f  (46.0927644486111, 14.4513975772133);
  glVertex2f  (46.4730047856893, 14.4205500023258);
  glVertex2f  (46.5085390956401, 14.318703540933);
 glVertex2f   (47.7470167676415, 14.3010110027623);
 glVertex2f   (48.0300973783846, 14.6725543043471);
  glVertex2f  (48.2866391818706, 14.7344781879446);
  glVertex2f  (48.5697197926138, 14.6902468425178);
 glVertex2f   (48.6404899452996, 14.2125483119087);
  glVertex2f  (48.0566361856418, 13.8410050103239);
    glEnd();

    glBegin(GL_POLYGON);
glColor3ub(65,83,59);
 glVertex2f   (46.2346134707797, 14.7536935260228);
 glVertex2f   (46.2693221163988, 14.7549292032705);
 glVertex2f   (46.27,14.43);
 glVertex2f   (46.2396658624616, 14.4410671824475);
    glEnd();

    glBegin(GL_POLYGON);
glColor3ub(65,83,59);
 glVertex2f   (48.2033214226626, 15.0723266047461);
 glVertex2f   (48.25364328717, 15.0754564443209);
 glVertex2f   (48.254,14.7267);
  glVertex2f  (48.206,14.71);
    glEnd();

        glBegin(GL_POLYGON);
glColor3ub(255,255,255);
   glVertex2f   (45.9547,14.117);
   glVertex2f   (46.0386,14.284);
   glVertex2f   (46.2498183833431, 14.2565802551505);
    glVertex2f  (46.1955948299073, 14.0509826150483);
    glEnd();
      glBegin(GL_POLYGON);
glColor3ub(255,255,255);
  glVertex2f (46.7694607704363, 14.1481331482834);
  glVertex2f (46.868870618402, 14.1481331482834);
  glVertex2f (46.868870618402, 14.0600198739539);
  glVertex2f (46.7739793998893, 14.0532419297747);
  glEnd();
    glBegin(GL_POLYGON);
glColor3ub(255,255,255);
  glVertex2f (47.0044295019915, 14.1616890366418);
  glVertex2f (47.0902834615983, 14.1616890366418);
  glVertex2f (47.0925427763247, 14.0532419297747);
  glVertex2f (47.011207446171, 14.0464639855955);
  glEnd();
    glBegin(GL_POLYGON);
glColor3ub(255,255,255);
  glVertex2f (47.2868438428031, 14.1639483513682);
  glVertex2f (47.3975502644012, 14.1662076660946);
  glVertex2f (47.4020688938542, 14.0509826150483);
  glVertex2f (47.2845845280766, 14.0555012445011);
  glEnd();
      glBegin(GL_POLYGON);
glColor3ub(255,255,255);
  glVertex2f  (47.5574568372804, 14.1665751407528);
  glVertex2f (47.6815860767256, 14.1734712096106);
    glVertex2f (47.6850341111546, 14.0562380390284);
   glVertex2f (47.5643529061385, 14.0562380390284);
     glEnd();
}

void drawcargo(){
    glPushMatrix();
glTranslatef(_move13, 0.0f, 0.0f);
cargo();
glPopMatrix();
}
void blade2(){

    glBegin(GL_POLYGON);
glColor3ub(0,0,0);
  glVertex2f  (45.2809551198828, 14.6485929076028);
  glVertex2f  (47.2535045352385, 14.6578104282349);
   glVertex2f (47.2581132955547, 14.5886790234941);
   glVertex2f (45.2809551198828, 14.584070263178);
    glEnd();

    glBegin(GL_POLYGON);
glColor3ub(0,0,0);
 glVertex2f   (47.0977150438414, 14.9918773080665);
  glVertex2f  (49.3690332523709, 15.0063972176122);
  glVertex2f  (49.3754936468606, 14.9351311678701);
  glVertex2f  (47.105683126046, 14.9351311678701);
    glEnd();
}
void drawcargoblade(){
       glPushMatrix();
glTranslatef(_move13, 0.0f, 0.0f);
glRotatef(_angle2,1.0f,0.0f,0.0f);
blade2();
glPopMatrix();
}

void drawfiref(){
     if (!isFalling) {
glPushMatrix();
glTranslatef(_move, 0.0f, position7);
fire2();
glPopMatrix();
     }
}

void update5 (int value) {
      position7 -= 5;
    if(position7 <-80){
        position7 = +1.0f;
}
	glutPostRedisplay();
	glutTimerFunc(10, update5, 0);
}

bool checkCollision(float missileX, float missileY, float tankX, float tankY, float tankWidth, float tankHeight) {
    // Check if missile's bounding box intersects with tank's bounding box
    return (missileX < tankX + tankWidth &&
            missileX + missileWidth > tankX &&
            missileY < tankY + tankHeight &&
            missileY + missileHeight > tankY);
}

void update7(int value) {
    if (isFalling) {
        missileY1 -= 0.05f; // Adjust the speed as needed

        if (missileY1 <= tankY && checkCollision(2.4061680739517, missileY1, tankX, tankY, tankWidth, tankHeight)) {
            // Handle collision here
            isFalling = false; // Stop the missile
            glutPostRedisplay(); // Redisplay to draw the tank and missile before drawing the fire
            fire2(); // Call fire2 function to draw fire
            isTankMoveAllowed = false; // Stop tank movement permanently
            return;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(16, update7, 0); // Update every 16 milliseconds (about 60 frames per second)
}
void boat2(float& boat_x, float& boat_y, float& boat_width, float& boat_height) {
    // Calculate boat's position and dimensions
    boat_x = 0.2098463093678;
    boat_y = 5.2878214212904;
    boat_width = 3.6374640915587 - 0.2098463093678;
    boat_height = 5.7699962180559 - 5.2878214212904;
}

void update8(int value) {
    if (missileFalling2) {
        missileY2 += 0.05f; // Adjust this value to control the speed of the missile drop
        if (missile_hits_boat()) {
            missileFalling2 = false;
            // Call the function to draw the boat on fire
            drawboatfire();
        }
        glutPostRedisplay(); // Request a redraw
    }
    glutTimerFunc(16, update8, 0);  // Call update again in 16 milliseconds (about 60 FPS)
}

bool missile_hits_boat() {
    // Boat position and dimensions
    float boat_x, boat_y, boat_width, boat_height;
    boat2(boat_x, boat_y, boat_width, boat_height);

    // Calculate top and bottom y-coordinates of the boat
    float boatTopY = boat_y + boat_height;
    float boatBottomY = boat_y;

    // Calculate top and bottom y-coordinates of the missile
    float missileTopY = 16.2649115355717 - missileY2;
    float missileBottomY = 16.2093842448336 - missileY2;

    // Check for collision
    if (missileBottomY <= boatTopY && missileTopY >= boatBottomY) {
        return true; // Collision detected
    }
    return false; // No collision detected
}

void display(){
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
bac();
grass();
drawcar();
bridge();
water();
building6();
building2();
building5();
building3();
building4();
building();
building8();
building7();
drawbuilding();
drawbuilding1();
building12();
tree2();
b11();
w11();
w12();
w13();
w14();
b12();
tree();
wood();
drawboat2();
drawboatfire();
drawboat();
bridge2();
road();
Road2();
road3();
line();
line2();
line3();
line4();
line5();
line6();
line7();
line8();
line9();
line10();
line11();
line13();
line14();
line15();
line16();
line17();
line18();
window();
window2();
window3();
window4();
win();
win2();
win3();
win4();
wi1();
wi2();
wi3();
wi4();
drawcloud2();
drawhelimissile();
drawTank();
drawairship();
drawcloud();
drawplane();
w();
w2();
w3();
w4();
w5();
w6();
drawtruck();
drawtire();
drawheli();
drawblade();
drawcargo();
drawcargoblade();
drawfire();
drawtank2();

if (!isFalling) {
drawfiref();
}
glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'd' && !missileFalling && !truckHit) { // Only trigger missile fall if it's not already falling and truck not hit
        missileFalling = true;
    }
         switch (key) {
    case 's':
    case 'S':
        if (!isFalling) {
            isFalling = true;
             glutPostRedisplay(); // Start falling only if not already falling
            //update7(0); // Start the update timer
        }
        break;
    }

    if ((key == 'p' || key == 'P') && !missileFalling2) {
        missileFalling2 = true;
        planemissile(); // Set the flag to true when 'P' is pressed
    }
}




int main(int argc, char** argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutCreateWindow("WAR Scenario");
glutInitWindowSize(1920, 1200);
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
gluOrtho2D(0, 45.05, -0.10, 20);
glutTimerFunc(20, update, 0);
glutTimerFunc(10, update2, 0);
glutTimerFunc(10, update3, 0);
glutTimerFunc(20, update4, 0);
glutTimerFunc(10, update6, 0);
glutTimerFunc(16, update7, 0);
glutTimerFunc(10, update5, 0);
glutTimerFunc(16, update8, 0);
glutMainLoop();
return 0;
}
