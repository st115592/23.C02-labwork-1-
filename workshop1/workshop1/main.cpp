#include <iostream>
#include <fstream>
#include "DataProc.h"


void writeToLatex(const std::string& outputFileName, const DataProcessor& processor) {
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Не удалось открыть файл");
    }
    outputFile << "\\documentclass{article}\n"
        << "\\begin{document}\n"
        << "\\begin{tabular}{|c|c|}\n"
        << "\\hline\n"
        << "Отклонение и квадрат отклонения \\\\\n"
        << "\\hline\n";

    const std::vector<double>& deviations = processor.getDeviations();
    const std::vector<double>& squaredDeviations = processor.getSquaredDeviations();

    for (size_t i = 0; i < deviations.size(); ++i) {
        outputFile << deviations[i] << " & " << squaredDeviations[i] << " \\\\\n";
    }

    outputFile << "\\hline\n"
        << "\\multicolumn{2}{|c|}{max absolute deviation Delta: " << processor.getMaxDelta() << "} \\\\\n"
        << "\\hline\n"
        << "\\multicolumn{2}{|c|}{mean square deviation sigma: " << processor.getStandardDeviation() << "} \\\\\n"
        << "\\hline\n"
        << "\\multicolumn{2}{|c|}{mean square deviation of the mean: " << processor.getMeanError() << "} \\\\\n"
        << "\\hline\n"
        << "\\end{tabular}\n"
        << "\\end{document}\n";

    outputFile.close();
}

int main() {
    try {
        DataProcessor processor("data.txt");
        processor.readData();
        processor.calculateMean();
        processor.calculateDeviations();
        processor.calculateAbsoluteErrors();
        processor.calculateStandardDeviation();
        processor.calculateMeanError();
        writeToLatex("out.tex", processor);
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}