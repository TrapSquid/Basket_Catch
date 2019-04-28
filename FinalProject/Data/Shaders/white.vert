

//Handles Object's positioning and scaling uniforms
uniform vec2 u_ChangePosition;
uniform vec2 u_ObjectScale;

uniform float u_Time;

attribute vec2 a_Position;
varying float v_Time;
varying vec2 v_Position;


void main()
{
vec2 finalpos = a_Position;
///Will not be using camera changes inside this.
////This is where we are handling object related translations
	finalpos *= u_ObjectScale; // apply object scale
	finalpos += u_ChangePosition; // apply object translation

    gl_Position = vec4( finalpos, 0, 1 );
	v_Time = u_Time;
	v_Position = a_Position;
}
