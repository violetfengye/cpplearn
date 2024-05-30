#include <iostream>
#include <vector>

// 感知机模型
class Perceptron
{
private:
    std::vector<float> weights; // 权重
    float bias;                 // 偏置
    float learningRate;         // 学习率

public:
    Perceptron(int numFeatures, float learningRate = 1.0) : bias(0), learningRate(learningRate)
    {
        weights.resize(numFeatures, 0);
    }

    // 符号函数
    int sign(float x)
    {
        return (x >= 0) ? 1 : -1;
    }

    // 预测函数
    int predict(const std::vector<float> &features)
    {
        float sum = bias;
        for (size_t i = 0; i < weights.size(); ++i)
        {
            sum += weights[i] * features[i];
        }
        return sign(sum);
    }

    // 训练函数
    void train(const std::vector<std::vector<float>> &trainingData, const std::vector<int> &labels)
    {
        bool allClassified = false;
        while (!allClassified)
        {
            allClassified = true;
            for (size_t i = 0; i < trainingData.size(); ++i)
            {
                int output = predict(trainingData[i]);
                if (output != labels[i])
                {
                    allClassified = false;
                    for (size_t j = 0; j < weights.size(); ++j)
                    {
                        weights[j] += learningRate * labels[i] * trainingData[i][j];
                    }
                    bias += learningRate * labels[i];
                }
            }
        }
    }
};

int main()
{
    // 假设我们有以下训练数据和标签
    std::vector<std::vector<float>> trainingData = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
    std::vector<int> labels = {-1, 1, 1, -1};

    // 创建感知机实例
    Perceptron perceptron(2);

    // 训练感知机
    perceptron.train(trainingData, labels);

    // 测试感知机
    std::vector<float> testFeatures = {1, 0};
    int predictedLabel = perceptron.predict(testFeatures);
    std::cout << "Predicted label for [1, 0] is: " << predictedLabel << std::endl;

    return 0;
}
