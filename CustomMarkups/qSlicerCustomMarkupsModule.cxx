/*==============================================================================

  Copyright (c) The Intervention Centre
  Oslo University Hospital, Oslo, Norway. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Rafael Palomar (The Intervention Centre,
  Oslo University Hospital) and was supported by The Research Council of Norway
  through the ALive project (grant nr. 311393).

==============================================================================*/

#include "qSlicerCustomMarkupsModule.h"


// Qt includes
#include <QDebug>

// CustomMarkups Logic includes
#include "vtkSlicerCustomMarkupsLogic.h"

// CustomMarkups Widgets includes
#include "qMRMLMarkupsTestLineWidget.h"

// Markups Widgets includes
#include "qMRMLMarkupsOptionsWidgetsFactory.h"

#include <qSlicerModuleManager.h>
#include <qSlicerApplication.h>

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerCustomMarkupsModulePrivate
{
public:
  qSlicerCustomMarkupsModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerCustomMarkupsModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerCustomMarkupsModulePrivate::qSlicerCustomMarkupsModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerCustomMarkupsModule methods

//-----------------------------------------------------------------------------
qSlicerCustomMarkupsModule::qSlicerCustomMarkupsModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerCustomMarkupsModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerCustomMarkupsModule::~qSlicerCustomMarkupsModule()
{
}

//-----------------------------------------------------------------------------
bool qSlicerCustomMarkupsModule::isHidden() const
{
  // The module has no GUI.
  // Widget options will be shown in Markups module.
  return true;
}

//-----------------------------------------------------------------------------
QString qSlicerCustomMarkupsModule::helpText() const
{
  return "This module contains fundamental markups to be used in the Slicer-Liver extension.";
}

//-----------------------------------------------------------------------------
QString qSlicerCustomMarkupsModule::acknowledgementText() const
{
  return "This work has been partially funded by The Research Council of Norway (grant nr. 311393)";
}

//-----------------------------------------------------------------------------
QStringList qSlicerCustomMarkupsModule::contributors() const
{
  QStringList moduleContributors;
  moduleContributors << QString("Rafael Palomar (Oslo University Hospital / NTNU)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerCustomMarkupsModule::icon() const
{
  return QIcon(":/Icons/CustomMarkups.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerCustomMarkupsModule::categories() const
{
  return QStringList() << "Testing.TestCases";
}

//-----------------------------------------------------------------------------
QStringList qSlicerCustomMarkupsModule::dependencies() const
{
  return QStringList() << "Markups";
}

//-----------------------------------------------------------------------------
void qSlicerCustomMarkupsModule::setup()
{
  this->Superclass::setup();

  // Create and configure the options widgets
  auto optionsWidgetFactory = qMRMLMarkupsOptionsWidgetsFactory::instance();
  optionsWidgetFactory->registerOptionsWidget(new qMRMLMarkupsTestLineWidget());
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation* qSlicerCustomMarkupsModule::createWidgetRepresentation()
{
  return nullptr;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerCustomMarkupsModule::createLogic()
{
  return vtkSlicerCustomMarkupsLogic::New();
}
