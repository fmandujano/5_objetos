#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	posx = 0;
	posy = 0;
	radioCirculo = 20;

	Entity e = Entity();
	e.posX = 100;
	e.posY = 100;
	gameObjects.push_back(e);
	Entity e2 = Entity();
	e2.posX = 150;
	e2.posY = 150;
	gameObjects.push_back(e2);

	std::cout << gameObjects.size() << "\n";

}

//--------------------------------------------------------------
void ofApp::update()
{
	//mover les entidades
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i].posX += 1 * ofGetLastFrameTime();
		gameObjects[i].posY += 2 * ofGetLastFrameTime();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::cornflowerBlue);

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
void ofApp::mousePressed(int x, int y, int button){

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
