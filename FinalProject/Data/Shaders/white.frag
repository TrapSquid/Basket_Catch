varying vec2 v_Position;
uniform vec4 u_Color;
varying float v_Time;

void main()
{
//Checks to see if the pixels are less than the time so gives it a moving effect that counts up every second
	if(v_Position.y > v_Time)
	{
		gl_FragColor = u_Color;
	}
	else
	{
	//inverts the colors
		gl_FragColor = vec4(1,1,1,2) - u_Color;
	}
}