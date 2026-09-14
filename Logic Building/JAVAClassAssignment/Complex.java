
public class Complex {
	
	int real;
	int imag;
	
	Complex(int r , int i){
		
		real = r;
		imag = i;
	}
	
	
	Complex add(Complex c) {
		return new Complex(real+c.real,imag +c.imag);
	}
	
	Complex Subtract(Complex c) {
		return new Complex(real-c.real,imag -c.imag);
	}
	
	Complex multiply(Complex c) {
        int r = (real * c.real) - (imag * c.imag);
        int i = (real * c.imag) + (imag * c.real);
        return new Complex(r, i);
        
        
	}
	
	
        void display() {
            if (imag >= 0)
                System.out.println(real + " + " + imag + "i");
            else
                System.out.println(real + " - " + (-imag) + "i");
        }
    }
