#ifndef MORPHOLOGICALTRANSFORMATIONMODEL_HPP
#define MORPHOLOGICALTRANSFORMATIONMODEL_HPP

#pragma once

#include <iostream>

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include <nodes/DataModelRegistry>
#include "PBNodeDataModel.hpp"
#include "CVImageData.hpp"
#include <opencv2/imgproc.hpp>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeValidationState;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.

typedef struct MorphologicalTransformationParameters{
    int miMorphMethod;
    int miKernelShape;
    cv::Size mCVSizeKernel;
    cv::Point mCVPointAnchor;
    int miIteration;
    int miBorderType;
    MorphologicalTransformationParameters()
        : miMorphMethod(cv::MORPH_OPEN),
          miKernelShape(cv::MORPH_RECT),
          mCVSizeKernel(cv::Size(3,3)),
          mCVPointAnchor(cv::Point(0,0)),
          miIteration(1),
          miBorderType(cv::BORDER_DEFAULT)
    {
    }
} MorphologicalTransformationParameters;


class MorphologicalTransformationModel : public PBNodeDataModel
{
    Q_OBJECT

public:
    MorphologicalTransformationModel();

    virtual
    ~MorphologicalTransformationModel() override {}

    QJsonObject
    save() const override;

    void
    restore(const QJsonObject &p) override;

    unsigned int
    nPorts(PortType portType) const override;

    NodeDataType
    dataType(PortType portType, PortIndex portIndex) const override;

    std::shared_ptr<NodeData>
    outData(PortIndex port) override;

    void
    setInData(std::shared_ptr<NodeData> nodeData, PortIndex) override;

    QWidget *
    embeddedWidget() override { return nullptr; }

    void
    setModelProperty( QString &, const QVariant & ) override;

    QPixmap
    minPixmap() const override { return _minPixmap; }

    static const QString _category;

    static const QString _model_name;

private:
    MorphologicalTransformationParameters mParams;
    std::shared_ptr<CVImageData> mpCVImageData { nullptr };
    std::shared_ptr<CVImageData> mpCVImageInData { nullptr };
    QPixmap _minPixmap;

    void processData(const std::shared_ptr<CVImageData>& in, std::shared_ptr<CVImageData>& out, const MorphologicalTransformationParameters& params);
};

#endif // MORPHOLOGICALTRANSFORMATIONMODEL_HPP
