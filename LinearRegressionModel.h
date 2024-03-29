#include<iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;


class Dataset{
    public:
        float **X;
        float *y;
        int number_predictor;
        int length;

        Dataset(){
        	
		}
        Dataset(float **X_train,float *y_train, int length_train, int number_predictor_train){
		    X = (float **) malloc(sizeof(float*)*length_train);
		    for(int i = 0; i < length_train; i++){
		        X[i] = (float *) malloc(sizeof(float)*number_predictor_train);
		        std::memcpy(X[i], X_train[i], sizeof(float)*number_predictor_train);
		    }
		
		    y = (float *) malloc(sizeof(float)*length_train);
		    std::memcpy(y, y_train, sizeof(float)*length_train);
		    
		    length = length_train;
		    number_predictor = number_predictor_train;
		}
        void copy(const Dataset &data){
	    X = (float **) malloc(sizeof(float*)*data.length);
	    for(int i = 0; i < data.length; i++){
	        X[i] = (float *) malloc(sizeof(float)*data.number_predictor);
	        std::memcpy(X[i], data.X[i], sizeof(float)*data.number_predictor);
	    }
	
	    y = (float *) malloc(sizeof(float)*data.length);
	    std::memcpy(y, data.y, sizeof(float)*data.length);
	    
	    length = data.length;
	    number_predictor = data.number_predictor;
	}
        ~Dataset(){
        	
		}

        void print_dataset(){
	    for(int i = 0; i < length; i++){
	        printf("\t\t\t\trow = %d: \n",i);
	        for(int j = 0; j < number_predictor; j++){
	            printf("\t\t\t\tX%d = %f\n",j,X[i][j]);
	        }
	        printf("\t\t\t\tY = %f",y[i]);
	    }
	
	    
	}
};

float mean_squared_error(float *y_pred, float *y_true, int length);
float sum_residual(Dataset data, float *y_pred, int current_predictor);
float residual_sum_of_square(float *y_pred, float *y_true, int length);



class Weights{
    private:
        int MAX_WEIGHTS;

    public:
        float* values;
        int number_weights;
        Weights(){
        	
		}
        void init(int number_predictor, int random_init){
	    // Random Init Variables
	    MAX_WEIGHTS = 100;
	    srand(time(0));  // random number generator
	
	    number_weights = number_predictor ;
	    values = (float *) std::malloc(sizeof(float)*number_weights);
	    for(int i=0; i<number_weights; i++){
	        if(random_init == 1){
	            values[i] = (rand() % MAX_WEIGHTS);
	        }else{
	            values[i] = 0;
	        }
	    }
	}
        ~Weights(){
        	
		}
        void update(Dataset data, float *y_pred, float learning_rate){
	    float multiplier = learning_rate/data.length;
	    // Update each weights
	    for(int i = 0; i < number_weights; i++){
	        float sum = (sum_residual(data,y_pred,i));
	       // printf("Sum = %f\n",sum);
	        values[i] = values[i] - multiplier*sum;
	    }
	}
};








class LinearRegressionModel{
    // Models Variable
    Dataset data;
    Weights weights;

    // Public function for user
    public:
        // Constructor
        LinearRegressionModel(const Dataset &data_train){
            // Setting Variables
            data.copy(data_train);
            weights.init(data.number_predictor, 0);
        }

        void print_weights(){
            char function_string[1000];
            printf("\t\t\tNumber weights = %d\n",weights.number_weights);
            strcpy(function_string, "\ty = ");
            for(int i = 0; i < weights.number_weights; i++){
                printf("\t\t\tWeights %d is = %f\n",i,weights.values[i]);
                char weight[20];
                sprintf(weight,"\t\t\t%.2f * x%d",weights.values[i],i);
                strcat(function_string, weight);
                if(i == weights.number_weights-1){
                    strcat(function_string,"\n");
                }else{
                    strcat(function_string," + ");
                }
            }
            printf("\t\t\t%s\n",function_string);
        }

        // Train the regression model with some data
        void train(int max_iteration, float learning_rate){

            // Mallocating some space for prediction
            float *y_pred = (float *) std::malloc(sizeof(float)*data.length);
            while(max_iteration > 0){

                fit(y_pred);
                weights.update(data, y_pred, learning_rate);
                
                float mse = mean_squared_error(y_pred,data.y,data.length);

                if(max_iteration % 100 == 0){
                    print_weights();
                    std::cout << "\t\t\tIteration left: " << max_iteration << "; MSE = " << mse << "\n";
                }
                max_iteration--;
            }
            free(y_pred);
        }

        float predict(float *x){
            float prediction = 0;
                for(int i = 0; i < weights.number_weights; i++){
                    prediction = prediction + weights.values[i]*x[i];
                }
            return prediction;
        }

    // Private function for algorithm
    private:
        // fit a line given some x and weights
        void fit(float *y_pred){
            for(int i = 0; i < data.length; i++){
                y_pred[i] = predict(data.X[i]);
            }
        }
};



float mean_squared_error(float *y_pred, float *y_true, int length){
    return residual_sum_of_square(y_pred,y_true,length)/length;
}

float residual_sum_of_square(float *y_pred, float *y_true, int length){
    float total = 0;
    float residual;
    for(int i = 0 ; i < length; i++){
        residual = (y_true[i] - y_pred[i]);
        total = total + (residual*residual);
    }
    return total;
}

float sum_residual(Dataset data, float *y_pred, int current_predictor){
    float total = 0;
    float residual;
    for(int i = 0 ; i < data.length; i++){
        residual = (y_pred[i] - data.y[i]);
        total = total + residual*data.X[i][current_predictor];
    }
    return total;
}

Dataset read_csv(const char* filename){
    // Variable Initialization
    float **X;
    float *y;
    int index = 0;
    int length = 0;
    int number_predictor = 0;

    // Reading File to get the number of x and y data points
    std::ifstream infile(filename);
    std::string line;
    while (std::getline(infile, line)){
        length++;
        // Calculate the number of predictors
        if(length == 1){
            int i = 0;
            while(line[i] != '\0'){
                if(line[i] == ','){
                    number_predictor++;
                }
                i++;
            }
        }
    }
    infile.close();

    // Mallocating space for X and y
    X = (float **) malloc(sizeof(float*)*length);
    for(int i = 0; i < length; i++){
        X[i] = (float *) malloc(sizeof(float)*number_predictor);
    }
    y = (float *) malloc(sizeof(float)*length);

    // Rereading the file to extract x and y values
    char comma;
    std::ifstream samefile(filename);
    int current_index = 0;
    while(std::getline(samefile,line)){

        std::stringstream line_stream(line);
        int current_predictor = 0;
        float number;
        while (line_stream >> number)
        {
            if(current_predictor == number_predictor){
                y[current_index] = number;
            }
            else{
                X[current_index][current_predictor] = number;
                current_predictor++;
            }

            if(line_stream.peek() == ','){
                line_stream.ignore();
            }

        }
        current_index++;
    }
    samefile.close();

    Dataset data = Dataset(X,y,length,number_predictor);
    return data;
}
	


