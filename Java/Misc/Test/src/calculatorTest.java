import org.junit.jupiter.api.*;

import static org.junit.jupiter.api.Assertions.*;

public class calculatorTest {

    @Test
    public void test(){
        System.out.println("inside test method");
        calculator calc = new calculator();

        assertEquals(calc.add(1,4),5);
    }

    @BeforeEach
    public void before_each(){
        System.out.println("before each test");
    }

    @AfterEach
    public void after_each(){
        System.out.println("after each test");
    }

    @BeforeAll
    static void before_all(){
        System.out.println("before all test");
    }

    @AfterAll
    static void after_all(){
        System.out.println("after all test");
    }
}