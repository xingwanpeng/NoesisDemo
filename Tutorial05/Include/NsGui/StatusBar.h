////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef __GUI_STATUSBAR_H__
#define __GUI_STATUSBAR_H__


#include <Noesis.h>
#include <NsGui/CoreApi.h>
#include <NsGui/ItemsControl.h>


namespace Noesis
{
namespace Gui
{

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Represents a control that displays items and information in a horizontal bar
/// (typically at the bottom) in an application window.
///
/// http://msdn.microsoft.com/en-us/library/system.windows.controls.primitives.statusbar.aspx
////////////////////////////////////////////////////////////////////////////////////////////////////
class NS_GUI_CORE_API StatusBar: public ItemsControl
{
public:
    /// Constructor
    StatusBar();

    /// Destructor
    ~StatusBar();

public:
    static const DependencyProperty* SeparatorStyleKey;

protected:
    /// From ItemsControl
    //@{
    Ptr<DependencyObject> GetContainerForItemOverride() const;
    NsBool IsItemItsOwnContainerOverride(Core::BaseComponent* item) const;
    void ApplyItemContainerStyle(DependencyObject* container) const;
    //@}

    NS_DECLARE_REFLECTION(StatusBar, ItemsControl)
};

}
}

#endif