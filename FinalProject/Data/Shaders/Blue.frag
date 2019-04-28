
//Holds the texture that is passed in
uniform sampler2D u_Texture;

//Holds onto the UV cords we pass over
varying vec2 v_UVCoord;
//Used to add to the offset
varying vec2 v_UVOffset;

uniform vec4 u_Color;


void main()
{
	vec4 Tex = texture2D(u_Texture, v_UVCoord + v_UVOffset);
	gl_FragColor = Tex;
}