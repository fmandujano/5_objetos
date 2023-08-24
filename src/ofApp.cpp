#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	posx = 0;
	posy = 0;
	radioCirculo = 20;

	Entity e = Entity();
	e.position->x = 100;
	e.position->y = 100;
	e.velocity -> x = 10;
	gameObjects.push_back(e);
	Entity e2 = Entity();
	e2.position->x = 150;
	e2.position->y = 150;
	gameObjects.push_back(e2);

	e2.velocity->x = 10;

	std::cout << gameObjects.size() << "\n";

	imgHogar.load("casa.png");

}

//--------------------------------------------------------------
void ofApp::update()
{
	//mover les entidades
	for (int i = 0; i < gameObjects.size(); i++)
	{

		//aplicar la aceleracion de la gravedad en el espacio
		gameObjects[i].velocity->y += gravity * ofGetLastFrameTime();


		//colision y rebote con el piso
		if (gameObjects[i].position->y >= ofGetHeight())
		{
			gameObjects[i].position->y = ofGetHeight();
			gameObjects[i].velocity->y *= -0.9;

		}

		//aplicar la velocidad como posicion
		gameObjects[i].position->x += gameObjects[i].velocity->x * ofGetLastFrameTime();
		gameObjects[i].position->y += gameObjects[i].velocity->y * ofGetLastFrameTime();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::cornflowerBlue);

	//dibujar los objetos del fondo como la casa
	imgHogar.draw(200, ofGetHeight() - imgHogar.getHeight());

	ofSetColor(240, 12, 12);
	ofCircle(posx, posy, radioCirculo);

	if (gameObjects.size() > 0)
	{
		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i].draw();
		}
	}



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

	posx = x;
	posy = y;

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	posx = x;
	posy = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	if (x >= 0 && y >= 0 && x <= ofGetWidth() && y <= ofGetHeight())
	{
		//spawnear (engendrar) un objeto nuevo y agregarlo a la losta
		Entity newEntity = Entity();
		newEntity.position->x = x;
		newEntity.position->y = y;
		gameObjects.push_back(newEntity);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
