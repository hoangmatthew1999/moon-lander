#pragma once

#include "ofMain.h"
#include  "ofxAssimpModelLoader.h"
#include "box.h"
#include "ray.h"
#include "Octree.h"


class particle {
	public: 
		glm::vec3 pos = glm::vec3(0,0,0);
		int size = 1;
		void update();
		void draw();

};
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void drawAxis(ofVec3f);
		void initLightingAndMaterials();
		void savePicture();
		void toggleWireframeMode();
		void togglePointsDisplay();
		void toggleSelectTerrain();
		void setCameraTarget();
		glm::vec3 getMousePointOnPlane();
		void drawBox(const Box &box);
		Box meshBounds(const ofMesh &);
		bool rayIntersectPlane(const ofVec3f &rayPoint, const ofVec3f &raydir, ofVec3f const &planePoint,
	const ofVec3f &planeNorm, ofVec3f &point);
		

		ofEasyCam cam;
		ofCamera top;
		ofCamera *theCam;
		ofxAssimpModelLoader terrain, lander;
		ofLight light;
		Box boundingBox;
		Box landerBounds;
	
		bool bAltKeyDown;
		bool bCtrlKeyDown;
		bool bWireframe;
		bool bDisplayPoints;
		bool bPointSelected;
		
		bool bLanderLoaded = false;
		bool bTerrainSelected;
		bool bLanderSelected = false;
	
		ofVec3f selectedPoint;
		ofVec3f intersectPoint;
		
		glm::vec3 mouseDownPos;


		const float selectionRange = 4.0;

		Octree octree;
		Box testBox;
		TreeNode selectedNode;
		ofxAssimpModelLoader mars;

		glm::vec3 pos;

		int time = 0;
		int velocity = 1;
		int fuel = 120;

		particle particleObj;



};
