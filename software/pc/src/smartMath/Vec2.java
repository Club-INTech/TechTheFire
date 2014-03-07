/* ============================================================================
 * 				Vec2 class
 * ============================================================================
 * 
 * Bi-dimentionnal vector 2 class. Simple-precision members.
 * Author : Dede
 * Refactoring : Martial
 */

/*
 *	TODO : 	Implement Matrix product, String conversion and parsing
 */

package smartMath;

/**
 * Classe de calcul de vecteurs de dimension 2
 * @author martial
 * @author pf
 *
 */

public class Vec2
{

	public float x;
	public float y;
	
	public Vec2()
	{
		x = 0;
		y = 0;
	}

	public Vec2(float requestedX, float requestedY)
	{
		x = requestedX;
		y = requestedY;
	}
	
	// Do not square a length, use squared length directly
	// to increase performances
	public float SquaredLength()
	{
		return x*x + y*y;
	}

	// Returns this vec2's magnitude
	public float Length()
	{
		return (float) Math.sqrt(SquaredLength());
	}
	
	// dot product
	public float dot(Vec2 other)
	{
		return x*other.x + y*other.y;
	}
	

	// build a new Vec2 by summing the calling Vec2 and the one in args
	public Vec2 PlusNewVector(Vec2 other)
	{
		return new Vec2(x + other.x, y + other.y);
	}
	
	// build a new Vec2 with the value obtained by decrementing the
	// calling Vec2 by the provided Vec2 in args
	public Vec2 MinusNewVector(Vec2 other)
	{
		return new Vec2(x - other.x, y - other.y);
	}

	public void Plus(Vec2 other)
	{
		x += other.x;
		y += other.y;
	}
	
	public void Minus(Vec2 other)
	{
		x -= other.x;
		y -= other.y;
	}

	public Vec2 clone()
	{
		return new Vec2(this.x, this.y);
	}
	
	public float SquaredDistance(Vec2 other)
	{
		return (x-other.x)*(x-other.x) + (y-other.y)*(y-other.y);
	}

	public float distance(Vec2 other)
	{
		return (float) Math.sqrt(SquaredDistance(other));
	}
	
	public String toString()
	{
		return "("+x+","+y+")";
	}
	
	public boolean equals(Vec2 other)
	{
		return x == other.x && y == other.y;
	}
	public Vec2 dotFloat(float a)
	{
		return new Vec2(x*a,y*a);
	}
	
}
